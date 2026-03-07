#include <stddef.h>

void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		fn(i, &str[i]);
		i += 1;
	}
}
