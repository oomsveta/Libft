*This project has been created as part of the 42 curriculum by lwicket.*

> \- My code is standard-complaint.  
> \- Did you mean compliant?  
> \- No  
> *[@vzverovich](https://x.com/vzverovich) on Twitter, February 10, 2022*

## ℹ️ Project Overview

> [!WARNING]
> This branch contains a stripped-down version of the project. It has been reorganized to match the expected structure of the assignment. Among other things, the test suite has been removed. See the main branch for the full, unabridged code.

The **Libft** (where *ft* stands for *Forty-Two*) is the very first project of the [42 School](https://en.wikipedia.org/wiki/42_(school)). It consists of reimplementing various functions from the [C Standard Library](https://en.wikipedia.org/wiki/C_standard_library), along with a few custom ones.

For the first projects of the 42 curriculum, students are not allowed to use any function from the standard library: everything must be reimplemented on top of [system calls](https://en.wikipedia.org/wiki/System_call) ([`write`](https://sites.uclouvain.be/SystInfo/manpages/man2/write.2.html), [`read`](https://sites.uclouvain.be/SystInfo/manpages/man2/read.2.html), etc.), with the sole exceptions of [`malloc` and `free`](https://sites.uclouvain.be/SystInfo/manpages/man3/malloc.3.html).

Beyond the evident goal of learning how things work under the hood, reimplementing their own library provides students with a set of functions they can reuse in future projects.

### Design Considerations

As an already seasoned developer, I wanted to make as much as I could out of this relatively small project, spending a lot of time and brainpower on seemingly tiny details.

In addition to what's normally expected for this project, my Libft features:
- **Strict compliance to the ISO C Standard**
- **Portability** (best effort): I made my code run on Linux, macOS (ARM), and Windows! I was careful only to rely on aspects that are well-defined by the Standard. As far as I know, the only deviation from this rule is my implementation of `memmove`, which assumes a linear memory model.
- **Legacy(?) performance tricks**: "SWAR" memory functions and branchless `ctype` functions. Memory functions, in particular, were a headache to implement without breaking the portability requirements.
- **Full test suite** based on the [Unity test framework](https://www.throwtheswitch.org/unity). Incidentally, this introduced me to the concept of [vendoring](https://stackoverflow.com/questions/26217488/what-is-vendoring) in a language without a package manager.
- A totally overkill Makefile with **proper dependency tracking**. I had a lot of fun learning about all the features of Makefiles and trying to cram as many as possible into my project

I had to get a little crafty at times to make it all work while complying to 42's Norm. 

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

The following functions are not part of the standard C library. Their implementation specifications are defined in the project assignment.

|Function|Prototype|Allowed|Description|
|--|--|--|--|
|`ft_itoa`|`char *ft_itoa(int n)`|`malloc`|Allocates and returns a string representing the integer `n`.|
|`ft_putchar_fd`|`void ft_putchar_fd(char c, int fd)`|`write`|Outputs the character `c` to the given file descriptor.|
|`ft_putstr_fd`|`void ft_putstr_fd(char *s, int fd)`|`write`|Outputs the string `s` to the given file descriptor.|
|`ft_putendl_fd`|`void ft_putendl_fd(char *s, int fd)`|`write`|Outputs the string `s` to the given file descriptor, followed by a newline.|
|`ft_putnbr_fd`|`void ft_putnbr_fd(int n, int fd)`|`write`|Outputs the integer `n` to the given file descriptor.|
|`ft_substr`|`char *ft_substr(const char *s, unsigned int start, size_t len)`|`malloc`|Allocates and returns a substring from `s`. The substring begins at index `start` and is of maximum size `len`.|
|`ft_strjoin`|`char *ft_strjoin(const char *s1, const char *s2)`|`malloc`|Allocates and returns a new string resulting from the concatenation of `s1` and `s2`.|
|`ft_strtrim`|`char *ft_strtrim(const char *s1, const char *set)`|`malloc`|Allocates and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end.|
|`ft_split`|`char **ft_split(const char *s, char c)`|`malloc`|Allocates and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array is NULL-terminated.|
|`ft_striteri`|`void ft_striteri(char *s, void (*f)(unsigned int, char *))`|*None*|Applies the function `f` to each character of the string `s`, passing its index as the first argument.|
|`ft_strmapi`|`char *ft_strmapi(const char *s, char (*f)(unsigned int, char))`|`malloc`|Allocates a new string where each character is the result of applying the function `f` to the corresponding character of `s`. The function `f` is passed the character's index as its first argument.|
|`ft_lstnew`|`t_list *ft_lstnew(void *content)`|`malloc`|Creates a new node with the given content; next is set to NULL.|
|`ft_lstadd_front`|`void ft_lstadd_front(t_list **lst, t_list *new)`|*None*|Adds `new` node at the beginning of the list.|
|`ft_lstadd_back`|`void ft_lstadd_back(t_list **lst, t_list *new)`|*None*|Adds `new` node at the end of the list.|
|`ft_lstsize`|`int ft_lstsize(t_list *lst)`|*None*|Counts the number of nodes in the list.|
|`ft_lstlast`|`t_list *ft_lstlast(t_list *lst)`|*None*|Returns the last node of the list.|
|`ft_lstdelone`|`void ft_lstdelone(t_list *lst, void (*del)(void *))`|`free`|Frees a node's content using `del`, then frees the node itself.|
|`ft_lstclear`|`void ft_lstclear(t_list **lst, void (*del)(void *))`|`free`|Deletes a list and all successors.|
|`ft_lstiter`|`void ft_lstiter(t_list *lst, void (*f)(void *))`|*None*|Applies `f` to the content of every node in the list.|
|`ft_lstmap`|`t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`|`free`, `malloc`|Creates a new list by applying `f` to each node. Uses `del` if allocation fails.|

## 🛠️ Build & Usage

### Requirements

- GCC or Clang
- [`ar`](https://en.wikipedia.org/wiki/Ar_(Unix)) for creating the archive
- [C23](https://en.cppreference.com/w/c/23.html) support
- A UNIX-like system (such as Linux or macOS)

As per the assignment, the code is compiled using `cc`. It is not specified which compiler `cc` refers to, but it is safe to assume that it will be either GCC or Clang.

> [!TIP]
> At the time I wrote this, on the Brussels campus, whether `cc` points to GCC or Clang actually varies from one machine to another.

~~My project relies on features from C99 (compound literals, inline functions, single-line comments and `stdbool.h`).~~  
My project makes use of the `[[nodiscard]]` attribute introduced in C23. Other than that, it doesn't leverage any feature newer than C99.

### Building the library

To compile the project, simply go to the `libft/` directory and run `make`:
```bash
cd libft/
make
```
This will produce a `libft.a` archive containing all the compiled `.o` object files, which you can then reuse in other projects.

### Building for Windows

My library supports cross-compilation for Windows via MinGW. First, ensure you have the necessary packages installed:
```bash
sudo apt install build-essential binutils-mingw-w64 gcc-mingw-w64
```
To compile the library, run the following command:
```bash
make windows
```
This will produce a `libft.lib` file, which you can then link into your projects targeting Windows.

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

### Memory Functions

I implemented the memory functions so that they could handle one word at a time, rather than processing buffers byte by byte (char by char). This, because of the portability goal I set myself, led to two big problems:
1. **Strict Type Aliasing**: Character types (like `unsigned char`) are the only types allowed to alias anything in Standard C. There is no standard C type the size of a word that wouldn't violate strict aliasing rules.
2. **Unaligned Memory Access**: In order to minimize branching (i.e. avoid looping until memory is aligned), my code unconditionally jumps to the next aligned memory boundary, then starts accessing memory word by word. However, the bytes located before that aligned address need to be processed too, as do the leftover bytes at the end of the buffer when the size is not a multiple of the alignment. To handle those, my implementation performs an unaligned access, which is not natively supported on some older architectures.

Both problems were solved using [GNU type attributes](https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Type-Attributes.html):
1. `__may_alias__`: Tells the compiler that this type may alias another, ensuring it won't make assumptions based on strict aliasing rules or accidentally optimize out important instructions.
2. `aligned (n)`: Tells the compiler that this type is aligned to n bytes. Setting an alignment requirement of 1 doesn't change the size of my word-sized type, but it explicitly permits unaligned access. This allows architectures that support unaligned writes to do them in one go, while safely breaking them down into separate byte instructions on architectures that don't.

I didn't use the C23 `alignas` specifier or standard attribute syntax because standard alignment specifiers cannot be applied to `typedef`s (only to variables and struct/union members), and standard attribute support on `typedef`s remains inconsistent across compilers.

If the GNU extensions aren't available, the memory functions fall back to using an `unsigned char`, which naturally avoids both of the aforementioned problems. All my memory functions were written to adapt themselves to whatever type is defined, meaning the only part of the code that needs to be conditionally compiled behind an `#ifdef` is the `typedef` itself.

#### A Note on `memmove`

The Standard definition of `memmove` has a wording that may seem a little odd at first glance:

> Copying takes place *as if the n characters from the object pointed to by s2 are first copied into a temporary array of n characters* that does not overlap the objects pointed to by s1 and s2, and then the n characters from the temporary array are copied into the object pointed to by s1.

The reason it's worded like that is that simply copying memory like `memcpy` would can lead to problems if the destination and source are part of the same object. A concrete example is shifting a buffer to the right. If the source and destination overlap, part of the source is located where the copy will happen. Therefore, writing to the destination would corrupt the source!

The usual way to handle this is to copy bytes backwards when the destination starts after the source and both overlap. That way, you ensure you only overwrite bytes that have already been copied.

If you want to be completely pedantic, though, `memmove` is theoretically impossible to implement in a 100% standard-compliant way.

This is because determining whether two buffers overlap typically requires comparing their addresses like this:
```c
if (dest < src + n && src < dest + n)
{
    // Buffers overlap
}
```
However, the C Standard strictly limits when you can relationally compare pointers:
> **When two pointers are compared, the result depends on the relative locations in the address space of the objects pointed to**. If two pointers to object types **both point to the same object**, or both point one past the last element of the **same array object**, they compare equal. [...] **In all other cases, the behavior is undefined**.

This means that any < or > comparison between two pointers pointing to completely different objects is technically Undefined Behavior™️.

This undefinedness can be mitigated by first casting the pointers to a `uintptr_t`, since the comparison between two integers is always well-defined.

However, even this isn't universally compliant because it assumes a linear (flat) memory model. On older segmented memory architectures, you might get two completely different integer values that actually point to the exact same physical memory address. In such cases, an integer comparison would fail to detect the overlap.

That said, the segmented memory model is kind of dead nowadays. So dead, in fact, that assuming a flat memory model and comparing pointer addresses should be fine in 99.999999999% of cases. Even really strict libc implementations like musl libc have been doing exactly that. There's just no way to do it that would be both absolutely portable and performant at the same time.

### The case of `errno`

At the time I'm writing this, there is a bug in the Moulinette code that will flag using `errno` as cheating. Long story short, in order to enable thread safety while keeping backward compatibility with existing code, `errno` is usually implemented as a macro that expands to a call to a function returning a thread-local variable.

But this is a problem because 42's exercises have a strict set of allowed functions. The way it works is that it compares the symbols in your compiled objects against a whitelist of allowed functions. This whitelist contains the functions allowed within the scope of the exercise, plus a few internal functions emitted by the compiler. If it detects anything that's neither on the whitelist nor defined by one of your objects, you get a -42 grade.

Historically, the school has been using macOS, where the location of `errno` is retrieved by a function called `__error`. As far as I can tell, this function is in the permanent whitelist of the Moulinette. The thing is, around 2024, 42 transitioned from macOS to Linux, but on Linux, this function is named `__errno_location` instead of `__error`. The pedagogical team forgot to update the whitelist, and `errno` now gets flagged as a forbidden function.

This means we can't use it in our project. Yet, `errno` is needed to implement calloc:
> The setting of errno and the [ENOMEM] error condition are mandatory if an insufficient memory condition occurs.
https://pubs.opengroup.org/onlinepubs/9799919799/functions/calloc.html

POSIX explicitly describes two situations in which errno should be set to `ENOMEM`:
> Insufficient memory is available, including the case when `nelem * elsize` would overflow

In the usual case of insufficient memory, we don't need to set `errno` ourselves. We just call `malloc` and let it set `errno` if the allocation fails. The interesting case is when `nelem * elsize` would overflow. This also requires us to set errno, but we can't do it directly because of that bug in the Moulinette.

Currently, the best workaround I found is to call `malloc(PTRDIFF_MAX)` to force a malloc failure and have it set errno for us:

```c
if (element_size != 0 && nbr_of_elements > SIZE_MAX / element_size)
{
	return (malloc(PTRDIFF_MAX));
}
```

This was tested on school computers with both GCC and Clang, and failed successfully 👍

It is still not perfect, though, since nothing in the Standard guarantees that this will fail. But in practice, it is highly unlikely that your computer will let you allocate 9,223,372 *tera*bytes of RAM.

> [!TIP]
> I had initially chosen to call `malloc(SIZE_MAX)`, but gcc caps the allocation limit at `PTRDIFF_MAX` with `-Walloc-size-larger-than=`, which results in a warning (turned into an error by `-Werror`) if this limit is exceeded. So `PTRDIFF_MAX` it will be!

I'm not updating my implementation in this repository because I want to keep it clean, but I will in the files I submit.

I reported the bug. Hopefully it'll be fixed.

### -O3 flag

I [already learned](https://github.com/oomsveta/42-Piscine-February-2026/tree/main/rush_02#the--o3-incident) the hard way that `-O3` could totally jeopardize my projects. That said, it was an interesting learning experience, and so I decided to use that flag again 🐱

This had the following consequences:
- I always have to do something with the return value of `write`. This is because, on Ubuntu, `gcc` is customized to define `_FORTIFY_SOURCE=3` when compiling with any level of optimization greater than 0. As a side effect, this requires you to use the return value of `write`; otherwise, it emits a warning, which turns into a fatal error thanks to the mandatory `-Werror` flag. Simply casting to `(void)` isn't enough to silence the warning, so I used the return value in its intended way: to detect errors, and retry if possible.
- I had to compile with `-fno-builtin`, because the compiler was sometimes smart enough to detect that I was basically doing a `memcpy`. It would then replace my code with a call to the actual, builtin `memcpy` function. This would, of course, have been detected as the use of a forbidden function, which is punished by a `-42` grade. I used the command `nm -u <my_file.o>` to ensure all my objects only contained the allowed functions.

### atoi

\[REDACTED\]

### List functions and NULL heads

Many list functions operate on a "head", that is, a pointer to the variable holding the address of the first node of the list. The assignment doesn't mention the behavior a function like `ft_lstadd_back` should have if a null pointer is provided for the head.

I've seen a few fellow students' implementations [guarding](https://en.wikipedia.org/wiki/Guard_(computer_science)) the head, so that if it is `NULL`, the function just returns and does nothing. I strongly advocate against doing this. There is not a single legitimate situation where a null pointer should end up there. The head is essentially always computed using the address-of (`&`) operator, which will never yield `NULL` in any realistic scenario.

If `NULL` is passed as the head, it can only stem from a critical programming error or crafted malicious input, both of which I'd rather catch sooner than later. Guarding against it merely silences the error. It hides the bug rather than solving it, propagating the bad state downstream until the program eventually crashes or exhibits nonsensical behavior. By then, the origin of the bug is much harder to track down because it was silently passed from function call to function call.

TL;DR: I don't guard the head. It makes no sense. It hides bugs. It silently corrupts your whole program. Don't do that.

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

> ~~Science~~ *THE C STANDARD*, already oppressive with its shocking revelations, will perhaps be the ultimate exterminator of our human species - if separate species we be - for its reserve of unguessed horrors could never be borne by mortal brains if loosed upon the world  
> ― *H.P. Lovecraft* 

Type aliasing is that kind of cursed knowledge I almost wish I had never learned about. Because now I see problems in code I never suspected was broken, and I can't help but fix them.

Understanding the aliasing rules led me to rewrite my memory functions to make them (hopefully) portable. The following two articles were helpful in understanding the concept:

- [N3519 Understanding Effective Type Aliasing in C](https://www.open-std.org/jtc1/sc22/WG14/www/docs/n3519.pdf) by Eskil Steenberg
- [The joys and perils of C and C++ aliasing](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1) by Martin Sebor

### Linus' Good Taste

In a famous TED interview, Linus Torvalds demonstrates an approach to implementing linked-list functions that he considers "good taste" in coding. This used to be particularly helpful during my Piscine, but not so much when writing this library, unfortunately. I still used it to implement `lstmap`, though, so I guess it's still fair game to list it here. The following repository was a great help in understanding the concept: https://github.com/mkirchner/linked-list-good-taste

### AI usage

- **Proofreading**: This README has been proofread by AI. I had to yell at it an uncountable number of times because it kept altering my style. Hopefully, it didn't turn out too awkward. The section about `atoi` was heavily AI-generated. I regret it. I feel like my entire (otherwise handwritten!) README has lost its worth because of it. I'm going to wipe it out from the universe if I can find the time to rewrite it before I submit my project.
- **Coming up with test cases**
- **Acting as a search engine on steroids**

Someone said the AI revolution was a time of grief. Grief for the world that came before. I agree. Right now, I'm grieving. I wrote my Libft during the [bargaining stage](https://en.wikipedia.org/wiki/Five_stages_of_grief). Using AI as my search engine is currently as far as I'd go. 42's projects are my playground, and I don't want to ruin everything by giving up my fun time tinkering with computers to a machine. Well, I had an LLM generate a considerable chunk of the tests. But tests are never fun to write, so it doesn't count. (See? Bargaining stage! Told you!).
