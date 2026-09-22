CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS :=

CAN_WRAP_MALLOC := $(shell echo 'int main(){}' | $(CC) -Wl,--wrap=malloc -x c - -o /dev/null 2>/dev/null && echo 1 || echo 0)

ifeq ($(CAN_WRAP_MALLOC),1)
    CFLAGS  += -DCAN_WRAP_MALLOC
    LDFLAGS += -Wl,--wrap=malloc
endif

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

TEST_DIR := tests
UNITY_DIR := $(TEST_DIR)/unity/src
UNITY_AUTO := $(TEST_DIR)/unity/auto

INCLUDES := -I$(LIBFT_DIR) -I$(UNITY_DIR)

TEST_SRCS := $(filter-out %_runner.c, $(wildcard $(TEST_DIR)/test_*.c))

RUNNERS := $(TEST_SRCS:.c=_runner.c)
TEST_BINS := $(TEST_SRCS:.c=.out)

UNITY_OBJ := $(TEST_DIR)/unity.o

all: $(TEST_BINS)

# We want the sub-make to be called every time to ensure Libft is up-to-date,
# which is why we use a FORCE target. We can't use .PHONY because it would
# bypass timestamp checks altogether for any rule depending on libft.a, causing
# them to relink unnecessarily.
$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

FORCE:

$(UNITY_OBJ): $(UNITY_DIR)/unity.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

compile_commands.json: fclean
	bear -- $(MAKE) test

%_runner.c: %.c
	ruby $(UNITY_AUTO)/generate_test_runner.rb $< $@

%.out: %.c %_runner.c $(UNITY_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LDFLAGS) -o $@

test: $(TEST_BINS)
	@for bin in $(TEST_BINS); do \
		echo "\n=== Running $$bin ==="; \
		./$$bin || exit 1; \
	done

clean:
	$(RM) $(TEST_BINS) $(RUNNERS) $(UNITY_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all test clean fclean re
