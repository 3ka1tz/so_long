#include "../include/ft_printf.h"

int	printptr(uintptr_t p)
{
	if (!p)
		return (printstr("(nil)"));
	else
		return (printstr("0x") + printhex(p, "0123456789abcdef"));
}
