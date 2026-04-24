#include "../include/ft_printf.h"

#include <stdarg.h>

static int	handle_specifier(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (printchar(va_arg(ap, int)));
	if (specifier == 's')
		return (printstr(va_arg(ap, char *)));
	if (specifier == 'p')
		return (printptr(va_arg(ap, uintptr_t)));
	if (specifier == 'd' || specifier == 'i')
		return (printnbr(va_arg(ap, int)));
	if (specifier == 'u')
		return (printunbr(va_arg(ap, unsigned int)));
	if (specifier == 'x')
		return (printhex(va_arg(ap, unsigned long), "0123456789abcdef"));
	if (specifier == 'X')
		return (printhex(va_arg(ap, unsigned long), "0123456789ABCDEF"));
	if (specifier == '%')
		return (printchar('%'));
	return (printchar(specifier));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_specifier(format[i + 1], ap);
			i += 2;
		}
		else if (format[i] == '%')
			i++;
		else
		{
			count += printchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
