#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dest_len = ft_strnlen(dest, size);

	if (dest_len == size)
	{
		return (dest_len + ft_strlen(src));
	}
	return (dest_len + ft_strlcpy(dest + dest_len, src, size - dest_len));
}
