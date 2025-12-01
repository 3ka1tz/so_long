/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:11:34 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/12 12:45:24 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_printnbr_recursive(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_printnbr_recursive(n / 10);
	c = (n % 10) + '0';
	count += ft_printchar(c);
	return (count);
}

int	ft_printnbr(int n)
{
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	else if (n < 0)
		return (ft_printchar('-') + ft_printnbr_recursive((unsigned int)(-n)));
	else
		return (ft_printnbr_recursive((unsigned int)n));
}

int	ft_printunbr(unsigned int n)
{
	return (ft_printnbr_recursive(n));
}

int	ft_printhex(unsigned int n, int lower_upper)
{
	char	*hex;
	int		count;

	if (lower_upper == 0)
		hex = "0123456789abcdef";
	else if (lower_upper == 1)
		hex = "0123456789ABCDEF";
	count = 0;
	if (n == 0)
		return (ft_printchar('0'));
	if (n >= 16)
		count += ft_printhex(n / 16, lower_upper);
	count += ft_printchar(hex[n % 16]);
	return (count);
}

int	ft_printptr(void *ptr)
{
	unsigned long int	addr;
	char				hex[16];
	int					count;
	int					i;
	int					hex_digit;

	addr = (unsigned long int)ptr;
	if (!addr)
		return (ft_printstr("(nil)"));
	count = ft_printstr("0x");
	i = 0;
	while (addr)
	{
		hex_digit = addr % 16;
		if (hex_digit > 9)
			hex[i++] = hex_digit - 10 + 'a';
		else
			hex[i++] = hex_digit + '0';
		addr = addr / 16;
	}
	i--;
	while (i >= 0)
		count += write(1, (&hex[i--]), 1);
	return (count);
}
