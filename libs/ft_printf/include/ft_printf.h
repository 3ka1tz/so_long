#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>

int	ft_printf(const char *format, ...);

int	printchar(int c);
int	printstr(const char *s);
int	printptr(uintptr_t p);
int	printnbr(int n);
int	printunbr(unsigned int un);
int	printhex(unsigned long ul, const char *base);

#endif
