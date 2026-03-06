NAME = libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -MMD -MP

ifdef DEBUG
    CC := clang
    CFLAGS += -g3 -Og -fsanitize=undefined
else
    CFLAGS += -O3 -g0
endif

ifdef ASAN
	CFLAGS += -fsanitize=address
endif

SRC := ft_strdup.c
OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)

AR ?= ar

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -- $(OBJ) $(DEP)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

norm:
	norminette $(SRC) *.h

-include $(DEP)

.PHONY: all clean fclean re norm
