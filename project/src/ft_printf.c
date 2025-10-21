/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:11:37 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/12 12:54:06 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_handle_specifier(const char **format, va_list args)
{
	int	count;

	count = 0;
	if (**format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (**format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_printunbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_printhex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_printhex(va_arg(args, unsigned int), 1);
	else if (**format == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (**format == '%')
		count += ft_printchar('%');
	else
		count += ft_printchar('%') + ft_printchar(**format);
	(*format)++;
	return (count);
}

int	ft_process_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_specifier(&format, args);
		}
		else
		{
			count += ft_printchar(*format);
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = ft_process_format(format, args);
	va_end(args);
	return (count);
}
