#include <limits.h>
#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 2];
	char			*nptr;
	unsigned int	acc;

	nptr = buffer + sizeof buffer;
	acc = ft_abs(n);
	while (acc >= 10)
	{
		*--nptr = acc % 10 | '0';
		acc /= 10;
	}
	*--nptr = acc % 10 | '0';
	if (n < 0)
	{
		*--nptr = '-';
	}
	(void)write(fd, nptr, buffer + sizeof buffer - nptr);
}
