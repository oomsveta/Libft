*This project has been created as part of the 42 curriculum by lwicket*

## Project Overview

> [!WARNING]
> This project is still a work in progress. Its contents, along with the information in this README file, are subject to change.

The **Libft** (where *ft* stands for *Forty-Two*) is the very first project of the [42 School](https://en.wikipedia.org/wiki/42_(school)). It consists of reimplementing various functions from the C Standard Library, along with a few custom ones.

For the first projects of the 42 curriculum, students are not allowed to use any function from the standard library: everything must be reimplemented on top of system calls (`write`, `read`, etc.), with the sole exceptions of `malloc` and `free`.

Beyond the pedagogical goal of learning how things work under the hood, reimplementing their own library provides students with a set of functions they can reuse in future projects.

### Contents

#### 1. Libc Functions

The following functions from the standard C library must be reimplemented:

||name|allowed functions|
|--|--|--|
|☐|atoi||
|✅|bzero||
|☐|calloc|malloc|
|✅|isalnum||
|✅|isalpha||
|✅|isascii||
|✅|isdigit||
|✅|isprint||
|☐|memchr||
|☐|memcmp||
|✅|memcpy||
|✅|memmove||
|✅|memset||
|✅|strchr||
|✅|strdup|malloc|
|✅|strlcat||
|✅|strlcpy||
|✅|strlen||
|✅|strncmp||
|☐|strnstr||
|✅|strrchr||
|✅|tolower||
|✅|toupper||

#### 2. Extra Functions

Functions that aren't part of the standard library, whose specifications were given in the assignment PDF.

||name|allowed functions|
|--|--|--|
|✅|ft_itoa|malloc|
|✅|ft_putchar_fd|write|
|✅|ft_putendl_fd|write|
|✅|ft_putnbr_fd|write|
|✅|ft_putstr_fd|write|
|✅|ft_split|free, malloc|
|✅|ft_striteri||
|✅|ft_strjoin|malloc|
|✅|ft_strmapi|malloc|
|✅|ft_strtrim|malloc|
|✅|ft_substr|malloc|

#### 3. Linked Lists

||name|allowed functions|
|--|--|--|
|☐|ft_lstadd_back||
|☐|ft_lstadd_front||
|☐|ft_lstclear||
|☐|ft_lstdelone|free|
|☐|ft_lstiter||
|☐|ft_lstlast||
|☐|ft_lstmap||
|☐|ft_lstnew|malloc|
|☐|ft_lstsize||

## Installation & Usage

> [!WARNING]
> The I/O for this project is implemented on top of UNIX syscalls, which means you will need a UNIX-like system (such as Linux or macOS) to compile and run it.

### Compilation

To compile the project, simply go to the `libft/` directory and run `make`:
```bash
cd libft/
make
```
This will produce a `libft.a` archive containing all the compiled `.o` object files, which you can then reuse in other projects.

### Compiling with libft.a

```bash
cc <your src/obj files> libft.a -I<path to the directory containing libft.h>
```

> [!WARNING]
> `libft.a` must come AFTER everything that uses it in the list of files you provide to the compiler. This is because the linker discards all the functions in your archive that aren't currently needed, and its list of necessary functions is based exclusively on the objects it has parsed so far. If `libft.a` is the very first file provided in your link command, all of its contents will be discarded!

### Embedding in another project

Some 42 projects allow you to reuse your Libft. When that's the case, you aren't allowed to simply turn in the pre-compiled `libft.a` archive; you have to build it directly within your project's build process.

To do so, just copy/paste the `libft/` directory at the root of your project, along with its `Makefile`, header, and source files.

Then, update the main `Makefile` of your project to add the following variables:

```Makefile
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
```

Append the following options to your compiler flags:

```Makefile
LDFLAGS += -L$(LIBFT_DIR)
LDLIBS += -lft
CPPFLAGS += -I$(LIBFT_DIR)
```

> [!WARNING]
> Make sure you use `$(CPPFLAGS)` in your implicit rules to compile objects from sources, otherwise the C preprocessor won't be able to find `libft.h`.

You can now create a rule to build the Libft and add it as a dependency to your main linking rule:

```Makefile
$(LIBFT): $(LIBFT_DIR)/Makefile
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
```
*(Notice how `$(OBJ)` comes before `$(LDLIBS)` to respect the linking order mentioned earlier).*

Don't forget to update your clean/fclean rules too:

```Makefile
clean:
	$(RM) -r -- $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -- $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
```

## 📋 Coding Style

My coding style conforms to the [Norm](./norm.en.pdf), a set of strict styling guidelines enforced for all C exercises, which all students must follow under penalty of a zero grade.

Beyond purely cosmetic considerations, the Norm also forbids the following language constructs:

- `for` loops
- `do … while` loops
- `switch` statements
- `goto`
- the ternary operator
- declarations with initialization
- assignments inside controlling expressions

(non-exhaustive list)

> [!TIP]
> You can find the latest version of the Norm in the [Norminette repository](https://github.com/42School/norminette) – the program used to check conformity with the Norm. The version of the Norm included in this repository is the one that was in use when I completed this project.

## References & Acknowledgments

### ISO/IEC 9899:2024 aka C23

This is the official document that defines the behavior required of conforming C implementations. I used it as the authoritative reference for the behavior of every libc function.

You can purchase the Standard for the modest sum of 227 CHF on iso.org. Alternatively, you can download a free draft version that is 99% identical to the final version: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf

### musl libc

musl was my main reference when implementing the libc functions. It's a treasure trove of clever C code, full of branchless techniques and SWAR tricks, while always keeping portability and safety in mind.

https://musl.libc.org/

### Linus' Good Taste

In a famous TED interview, Linus Torvalds demonstrates an approach to implementing linked list functions that he considers "good taste" in coding. This was particularly helpful when implementing functions that modify the head pointer. The following repository was a great help in understanding the concept: https://github.com/mkirchner/linked-list-good-taste
