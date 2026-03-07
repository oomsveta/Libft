#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	size_t	n;

	n = ft_strlen(str) + 1;
	chr = (unsigned char)chr;
	while (n--)
	{
		if (((unsigned char *)str)[n] == chr)
		{
			return ((char *)&str[n]);
		}
	}
	return (NULL);
}
