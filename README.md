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

## References & Acknowledgments

### ISO/IEC 9899:2024 aka C23

This is the official document that defines the behavior required of conforming C implementations. I used it as the authoritative reference for the behavior of every libc function.

You can purchase the Standard for the modest sum of 227 CHF on iso.org. Alternatively, you can download a free draft version that is 99% identical to the final version: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf

### musl libc

musl was my main reference when implementing the libc functions. It's a treasure trove of clever C code, full of branchless techniques and SWAR tricks, while always keeping portability and safety in mind.

https://musl.libc.org/

### Linus' Good Taste

In a famous TED interview, Linus Torvalds demonstrates an approach to implementing linked list functions that he considers "good taste" in coding. This was particularly helpful when implementing functions that modify the head pointer. The following repository was a great help in understanding the concept: https://github.com/mkirchner/linked-list-good-taste
