#include "../include/so_long.h"
#include <stdlib.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;

    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

void ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	count_words(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*end;

	start = *s;
	while (*start == c)
		start++;
	if (!*start)
	{
		*s = start;
		return (NULL);
	}
	end = start;
	while (*end && *end != c)
		end++;
	*s = end;
	return (ft_strndup(start, end - start));
}

void	free_split(char **result, int array_size)
{
	if (result)
	{
		while (array_size > 0)
			free(result[--array_size]);
		free(result);
	}
}

char	**ft_split(const char *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

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
