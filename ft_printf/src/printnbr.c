#include "../include/ft_printf.h"

static int	putnbr_recursive(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += putnbr_recursive(n / 10);
	c = (n % 10) + '0';
	count += printchar(c);
	return (count);
}

int	printnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += printchar('-');
		count += putnbr_recursive((unsigned int)(-n));
	}
	else
		count += putnbr_recursive((unsigned int)n);
	return (count);
}

int	printunbr(unsigned int un)
{
	return (putnbr_recursive(un));
}
