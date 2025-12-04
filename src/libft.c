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
