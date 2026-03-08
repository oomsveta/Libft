/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:01:27 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 15:44:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

# ifdef __GNUC__

typedef uintptr_t __attribute__((__may_alias__))	t_word;

# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char			**ft_split(const char *str, char separator);
char			*ft_stpcpy(char *dest, const char *src);
char			*ft_strchr(const char *str, int chr);
char			*ft_strchrnul(const char *str, int chr);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *str, const char *chars);
char			*ft_substr(const char *str, unsigned int start, size_t len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_lstsize(t_list *lst);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);
size_t			ft_strspn(const char *str, const char *spn);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list 			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *));
unsigned int	ft_abs(int n);
void			*ft_calloc(size_t nbr_of_elements, size_t element_size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *buffer, int byte, size_t size);
void			ft_bzero(void *buffer, size_t size);
void			ft_lstadd_back(t_list **head, t_list *node);
void			ft_lstadd_front(t_list **head, t_list *node);
void			ft_lstclear(t_list **head, void (*delete_fn)(void *));
void			ft_lstdelone(t_list *node, void (*delete_fn)(void *));
void			ft_lstiter(t_list *lst, void (*fn)(void *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);

#endif /* LIBFT_H */
