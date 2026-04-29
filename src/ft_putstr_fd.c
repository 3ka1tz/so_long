#include <unistd.h>

// #include "../include/libft.h"
#include "../include/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
