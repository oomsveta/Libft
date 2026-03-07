/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:01:27 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/07 15:17:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

# ifdef __GNUC__

typedef uintptr_t __attribute__((__may_alias__))	t_uintptr_alias;

# endif

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
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);
size_t			ft_strspn(const char *str, const char *spn);
unsigned int	ft_abs(int n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *buffer, int byte, size_t size);
void			ft_bzero(void *buffer, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);

#endif /* LIBFT_H */
