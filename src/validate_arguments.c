#include "../include/so_long.h"

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

void	validate_arguments(int argc, char **argv)
{
	char	*map_filename;
	size_t	filename_length;
	
	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("You must enter two arguments, no more and no less", 2);
		exit(EXIT_FAILURE);
	}
	map_filename = argv[1];
	filename_length = ft_strlen(map_filename);
	if (filename_length < 4 || ft_strncmp(map_filename + filename_length - 4, ".ber", 4))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Mapfile extension must be .ber", 2);
		exit(EXIT_FAILURE);
	}
}
