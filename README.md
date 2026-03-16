*This project has been created as part of the 42 curriculum by lwicket.*

## ℹ️ Project Overview

> [!WARNING]
> This project is still a work in progress. Its contents, along with the information in this README file, are subject to change.

The **Libft** (where *ft* stands for *Forty-Two*) is the very first project of the [42 School](https://en.wikipedia.org/wiki/42_(school)). It consists of reimplementing various functions from the C Standard Library, along with a few custom ones.

For the first projects of the 42 curriculum, students are not allowed to use any function from the standard library: everything must be reimplemented on top of system calls (`write`, `read`, etc.), with the sole exceptions of `malloc` and `free`.

Beyond the educational goal of learning how things work under the hood, reimplementing their own library provides students with a set of functions they can reuse in future projects.

### Design Considerations

I wanted my Libft to be an opportunity to learn advanced aspects of the C language, and therefore decided to approach it from the perspective of strict standard compliance and performance.

### Contents

#### 1. Libc Functions

The following functions from the standard C library must be reimplemented:

- [atoi](https://man7.org/linux/man-pages/man3/atoi.3.html)
- [bzero](https://man7.org/linux/man-pages/man3/bzero.3.html)
- [calloc](https://man7.org/linux/man-pages/man3/calloc.3.html)
- [isalnum](https://man7.org/linux/man-pages/man3/isalnum.3.html)
- [isalpha](https://man7.org/linux/man-pages/man3/isalpha.3.html)
- [isascii](https://man7.org/linux/man-pages/man3/isascii.3.html)
- [isdigit](https://man7.org/linux/man-pages/man3/isdigit.3.html)
- [isprint](https://man7.org/linux/man-pages/man3/isprint.3.html)
- [memchr](https://man7.org/linux/man-pages/man3/memchr.3.html)
- [memcmp](https://man7.org/linux/man-pages/man3/memcmp.3.html)
- [memcpy](https://man7.org/linux/man-pages/man3/memcpy.3.html)
- [memmove](https://man7.org/linux/man-pages/man3/memmove.3.html)
- [memset](https://man7.org/linux/man-pages/man3/memset.3.html)
- [strchr](https://man7.org/linux/man-pages/man3/strchr.3.html)
- [strdup](https://man7.org/linux/man-pages/man3/strdup.3.html)
- [strlcat](https://linux.die.net/man/3/strlcat)
- [strlcpy](https://linux.die.net/man/3/strlcpy)
- [strlen](https://man7.org/linux/man-pages/man3/strlen.3.html)
- [strncmp](https://man7.org/linux/man-pages/man3/strncmp.3.html)
- [strnstr](https://man7.org/linux/man-pages/man3/strnstr.3.html)
- [strrchr](https://man7.org/linux/man-pages/man3/strrchr.3.html)
- [tolower](https://man7.org/linux/man-pages/man3/tolower.3.html)
- [toupper](https://man7.org/linux/man-pages/man3/toupper.3.html)

#### 2. Custom Functions

The following functions aren't part of the standard library. Their specifications were given in the assignment PDF.

|||
|--|--|
|**Name**|ft_itoa|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char *ft_itoa(int n)`|
|**Description**|Converts an integer to its string representation, dynamically allocating the required memory.|

|||
|--|--|
|**Name**|ft_putchar_fd|
|**Allowed Functions**|`write`|
|**Prototype**|`void ft_putchar_fd(char c, int fd)`|
|**Description**|Writes the given character to the given file descriptor.|

|||
|--|--|
|**Name**|ft_putstr_fd|
|**Allowed Functions**|`write`|
|**Prototype**|`void ft_putstr_fd(char *s, int fd)`|
|**Description**|Writes the given string to the given file descriptor.|

|||
|--|--|
|**Name**|ft_putendl_fd|
|**Allowed Functions**|`write`|
|**Prototype**|`void ft_putendl_fd(char *s, int fd)`|
|**Description**|Writes the given string followed by a newline to the given file descriptor.|

|||
|--|--|
|**Name**|ft_putnbr_fd|
|**Allowed Functions**|`write`|
|**Prototype**|`void ft_putnbr_fd(int n, int fd)`|
|**Description**|Writes the string representation of the given `int` to the given file descriptor.|

|||
|--|--|
|**Name**|ft_substr|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char *ft_substr(const char *s, unsigned int start, size_t len)`|
|**Description**|Creates a substring from `s`, starting at index `start`, with a maximum length of `len`.|

|||
|--|--|
|**Name**|ft_strjoin|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char *ft_strjoin(const char *s1, const char *s2)`|
|**Description**|Allocates a string containing the concatenation of `s1` and `s2`.|

|||
|--|--|
|**Name**|ft_strtrim|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char *ft_strtrim(const char *s1, const char *set)`|
|**Description**|Allocates a string containing `s1` trimmed from the characters in `set`.|

|||
|--|--|
|**Name**|ft_split|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char **ft_split(const char *s, char c)`|
|**Description**|Returns an array of strings obtained by splitting `s` using the character `c` as a delimiter.|

|||
|--|--|
|**Name**|ft_striteri|
|**Allowed Functions**||
|**Prototype**|`void ft_striteri(char *s, void (*f)(unsigned int, char *))`|
|**Description**|Applies the function `f` to each char of the string `s`.|

|||
|--|--|
|**Name**|ft_strmapi|
|**Allowed Functions**|`malloc`|
|**Prototype**|`char *ft_strmapi(const char *s, char (*f)(unsigned int, char))`|
|**Description**|Creates a string containing the result of applying the function `f` to each char of the string `s`.|

#### 3. Linked Lists

||name|allowed functions|
|--|--|--|
|✅|ft_lstadd_back||
|✅|ft_lstadd_front||
|✅|ft_lstclear||
|✅|ft_lstdelone|free|
|✅|ft_lstiter||
|✅|ft_lstlast||
|✅|ft_lstmap||
|✅|ft_lstnew|malloc|
|✅|ft_lstsize||

## 🛠️ Build & Usage

### Requirements

- GCC or Clang
- [`ar`](https://en.wikipedia.org/wiki/Ar_(Unix)) for creating the archive
- [C99](https://en.cppreference.com/w/c/99.html) support
- A UNIX-like system (such as Linux or macOS)

As per the assignment, the code is compiled using `cc`. It is not specified which compiler `cc` refers to, but it is safe to assume that it will be either GCC or Clang.

> [!TIP]
> At the time I wrote this, on the Brussels campus, whether `cc` points to GCC or Clang actually varies from one machine to another.

My project relies on features from C99 (compound literals, inline functions, single-line comments and `stdbool.h`).

### Building the library

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

## 🧑‍🔬 Implementation Notes

### Memory Manipulaton Functions

I implemented the memory manipulation functions to handle one word at a time, rather than byte by byte (char by char). I had to overcome two main obstacles:
1. **Strict Type Aliasing**: Character types (like `unsigned char`) are the only types allowed to alias anything in Standard C. There is no standard C type the size of a word that wouldn't violate strict aliasing rules.
2. **Unaligned Memory Access**: In order to minimize branching, my code unconditionally jumps to the next aligned memory boundary, then starts accessing memory word by word. However, the bytes located before that aligned address need to be processed too, as do the leftover bytes at the end of the buffer when the size is not a multiple of the alignment. To handle those, I perform an unaligned access, which is not natively supported on some older architectures.

Both problems were solved using [GNU type attributes](https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Type-Attributes.html):
1. `__may_alias__`: Tells the compiler that this type may alias another, ensuring it won't make assumptions based on strict aliasing rules or accidentally optimize out important instructions.
2. `aligned (n)`: Tells the compiler that this type is aligned to n bytes. Setting an alignment requirement of 1 doesn't change the size of my word-sized type, but it explicitly permits unaligned access. This allows architectures that support unaligned writes to do them in one go, while safely breaking them down into separate byte instructions under the hood on architectures that don't.

I didn't use the C23 `alignas` specifier or standard attribute syntax because standard alignment specifiers cannot be applied to `typedef`s (only to variables and struct/union members), and standard attribute support on `typedef`s remains inconsistent across compilers.

If the GNU extensions aren't available, the memory functions fall back to using an `unsigned char`, which naturally avoids both of the aforementioned problems. All my memory functions were written to adapt themselves to whatever type is defined, meaning the only part of the code that needs to be conditionally compiled behind an `#ifdef` is the `typedef` itself.

### Compiler flags

#### -O3

I [already learned](https://github.com/oomsveta/42-Piscine-February-2026/tree/main/rush_02#the--o3-incident) the hard way that `-O3` could totally jeopardize my projects. That said, it was an interesting learning experience, and so I decided to use that flag again 🐱

This had the following consequences:
- I always have to do something with the return value of `write`. This is because, on Ubuntu, `gcc` is customized to define `_FORTIFY_SOURCE=3` when compiling with any level of optimization greater than 0. As a side effect, this requires you to use the return value of `write`; otherwise, it emits a warning, which turns into a fatal error thanks to the mandatory `-Werror` flag. Simply casting to `(void)` isn't enough to silence the warning, so I used the return value in its intended way: to detect errors, and retry if possible.
- I had to compile with `-fno-builtin`, because the compiler was sometimes smart enough to detect that I was basically doing a `memcpy`. It would then replace my code with a call to the actual, builtin `memcpy` function. This would, of course, have been detected as the use of a forbidden function, which is punished by a `-42` grade. I used the command `nm -u <my_file.o>` to ensure all my objects only contained the allowed functions.

### atoi

My implementation does nothing to detect or handle out-of-bounds overflow. I based this design choice on the following excerpt from the C Standard:
> The functions atof, **atoi**, atol, and atoll **need not affect the value of the integer expression errno on an error. If the value of the result cannot be represented, the behavior is undefined**.

However, my implementation ensures that all valid, representable values within the range of an `int` are parsed correctly without triggering internal overflows. This requires special care due to how string-to-integer conversion is typically implemented.

Usually, `atoi` calculates the result by reading digits into a positive accumulator (multiplying by 10 and adding the new digit), and only converts the final result to a negative number at the very end if a minus sign was detected. In C, [signed integer overflow is strict Undefined Behavior (UB)](https://wiki.sei.cmu.edu/confluence/spaces/c/pages/87152210/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow).

This standard accumulation strategy creates a subtle problem when parsing `INT_MIN`. In two's complement arithmetic, the absolute value of `INT_MIN` is exactly one greater than `INT_MAX`. Therefore, if the accumulator is simply declared as an `int`, parsing the string representation of `INT_MIN` will cause a signed integer overflow on the final digit, triggering UB before the negation step is ever reached.

On many common architectures, this bug goes completely unnoticed. The compiler's underlying behavior for signed overflow often defaults to two's complement wraparound, meaning the positive accumulator wraps completely around to the negative `INT_MIN` value. Negating `INT_MIN` typically yields `INT_MIN` again, making the function output the correct answer by sheer luck. However, relying on this is unsafe and violates the C standard; compiling the code with `-fsanitize=undefined` then running it flags this as an error.

To solve this, one might be tempted to use a larger signed type, such as `long`, for the accumulator. However, this is not a portable solution. The C Standard does not guarantee that `long` (or even a `long long` for that matter) is larger than `int`; for example, under the LLP64 data model used by 64-bit Windows, both `int` and `long` are exactly 32 bits.

Therefore, the only strictly portable way to safely accumulate digits and support `INT_MIN` is to use an `unsigned int` for the accumulator. Unsigned arithmetic is guaranteed by the Standard never to overflow (it operates using modulo arithmetic), and an `unsigned int` is perfectly capable of holding the absolute value of `INT_MIN` before the final sign logic is applied.

## 📚 References & Acknowledgments

### ISO/IEC 9899:2024 aka C23

This is the official document that defines the behavior required of conforming C implementations. I used it as the authoritative reference for the behavior of every libc function.

You can purchase the Standard for the modest sum of 227 CHF on iso.org. Alternatively, you can download a free draft version that is 99% identical to the final version: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf

### musl libc

musl was my main reference when implementing the libc functions. It's a treasure trove of clever C code, full of branchless techniques and SWAR tricks, while always keeping portability and safety in mind.

https://musl.libc.org/

### Sean Eron Anderson's Bit Twiddling Hacks

The definitive reference for bitwise tricks, a must-read for implementing SWAR strategies.

https://graphics.stanford.edu/~seander/bithacks.html

### GNU Manual: Type Attributes

https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Type-Attributes.html

### Type Aliasing

- [N3519 Understanding Effective Type Aliasing in C](https://www.open-std.org/jtc1/sc22/WG14/www/docs/n3519.pdf) by Eskil Steenberg
- [The joys and perils of C and C++ aliasing](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1) by Martin Sebor

### Linus' Good Taste

In a famous TED interview, Linus Torvalds demonstrates an approach to implementing linked list functions that he considers "good taste" in coding. This was particularly helpful when implementing functions that modify the head pointer. The following repository was a great help in understanding the concept: https://github.com/mkirchner/linked-list-good-taste

### ChatGPT 5.3(?)

This entire project has been handcrafted by a human (yours truly), but proofread by AI. Many thanks to the free version of ChatGPT for fixing my grammar and providing feedback on my cursed code!
