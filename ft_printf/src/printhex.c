#include "../include/ft_printf.h"

int	printhex(unsigned long ul, const char *base)
{
	int	count;

	count = 0;
	if (ul >= 16)
		count += printhex(ul / 16, base);
	count += printchar(base[ul % 16]);
	return (count);
}
