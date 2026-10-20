NAME := libft.a

CC := cc
AR := ar

ARFLAGS := rcs
CFLAGS := -Wall -Wextra -Werror -Wmissing-prototypes -Wvla -fPIC
DEPFLAGS := -MMD -MP
CPPFLAGS := $(DEPFLAGS) -I.

ifdef WINDOWS
	CC := x86_64-w64-mingw32-gcc
	AR := x86_64-w64-mingw32-ar
	NAME := libft.lib
endif

ifdef DEBUG
    CC := clang
    CFLAGS += -g3 -Og -fsanitize=undefined
else
    CFLAGS += -O3 -g0 -fno-builtin
endif

ifdef ASAN
	CFLAGS += -fsanitize=address
endif

STEMS := atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa \
         lstadd_back lstadd_front lstclear lstdelone lstiter lstlast lstmap \
         lstnew lstsize memchr memcmp memcpy memmove memset putchar_fd \
		 putendl_fd putnbr_fd putstr_fd split strchr strdup striteri strjoin \
		 strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim substr \
		 tolower toupper
SRC := $(STEMS:%=ft_%.c)
OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ): %.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -- $(OBJ) $(DEP)

fclean: clean
	$(RM) -- $(NAME)

re: fclean all

norm:
	norminette $(SRC) *.h

windows:
	@$(MAKE) WINDOWS=1 re

ifeq (,$(filter clean fclean norm re windows, $(MAKECMDGOALS)))
-include $(DEP)
endif

.PHONY: all clean fclean re norm windows
