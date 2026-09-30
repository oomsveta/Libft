CC      := cc
CFLAGS  := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a

TEST_DIR            := tests
TEST_SRCS           := $(filter-out %_runner.c, $(wildcard $(TEST_DIR)/test_*.c))
TEST_BINS           := $(TEST_SRCS:.c=.out)
UNITY_DIR           := $(TEST_DIR)/unity
UNITY_SRC           := $(UNITY_DIR)/src
UNITY_OBJ           := $(TEST_DIR)/unity.o
UNITY_AUTO          := $(UNITY_DIR)/auto
INCLUDES            := -I$(LIBFT_DIR) -I$(UNITY_SRC) -I$(TEST_DIR)
MALLOC_MOCK_HDR     := $(TEST_DIR)/malloc_mock.h
MALLOC_OVERRIDE_HDR := $(TEST_DIR)/malloc_override.h
MALLOC_MOCK_OBJ     := $(TEST_DIR)/malloc_mock.o
MOCKED_FUNCS        := ft_calloc ft_strjoin ft_strmapi ft_itoa ft_strdup ft_split ft_substr ft_lstnew ft_lstmap
MOCKED_OBJS         := $(addprefix $(TEST_DIR)/, $(addsuffix _mocked.o, $(MOCKED_FUNCS)))
RUNNERS             := $(TEST_SRCS:.c=_runner.c)

UNAME_S := $(shell uname -s)
CLANG_TIDY_FLAGS :=
ifeq ($(UNAME_S),Darwin)
    MAC_SDK := $(shell xcrun --show-sdk-path)
    CLANG_TIDY_FLAGS += -isysroot $(MAC_SDK)
endif

all: $(TEST_BINS)

test: $(TEST_BINS)
	@for bin in $(TEST_BINS); do \
		echo "\n=== Running $$bin ==="; \
		./$$bin || exit 1; \
	done

compile_commands.json: fclean
	bear -- $(MAKE) test

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

FORCE:

$(UNITY_OBJ): $(UNITY_SRC)/unity.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MALLOC_MOCK_OBJ): $(TEST_DIR)/malloc_mock.c $(MALLOC_MOCK_HDR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_DIR)/%_mocked.o: $(LIBFT_DIR)/%.c $(MALLOC_OVERRIDE_HDR)
	$(CC) $(CFLAGS) $(INCLUDES) -include $(MALLOC_OVERRIDE_HDR) -c $< -o $@

%_runner.c: %.c
	@ruby $(UNITY_AUTO)/generate_test_runner.rb $< $@

%.out: %.c %_runner.c $(UNITY_OBJ) $(MALLOC_MOCK_OBJ) $(MOCKED_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

clean:
	$(RM) $(TEST_BINS) $(RUNNERS) $(UNITY_OBJ) $(MOCKED_OBJS) $(MALLOC_MOCK_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

tidy:
	clang-tidy $$(find $(LIBFT_DIR) -type f -name "*.c") -- $(CLANG_TIDY_FLAGS)

.PHONY: all test clean fclean re tidy FORCE
