#include "../include/so_long.h"

#include <stddef.h>

static int	validate_argc(int argc)
{
	if (argc != 2)
		return (1);
	return (0);
}

static int	validate_filename(const char *filename)
{
	size_t	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (filename[len - 4] == '.'
		&& filename[len - 3] == 'b'
		&& filename[len - 2] == 'e'
		&& filename[len - 1] == 'r')
		return (0);
	return (1);
}

void	validate_arguments(int argc, char **argv)
{
	int	invalid_argc;
	int	invalid_filename;

	invalid_argc = validate_argc(argc);
	invalid_filename = validate_filename(argv[1]);
	if (invalid_argc || invalid_filename)
	{
		ft_putendl_fd("Error", 2);
		if (invalid_argc)
			ft_putendl_fd("Invalid argument count", 2);
		else if (invalid_filename)
			ft_putendl_fd("Invalid filename", 2);
		exit(EXIT_FAILURE);
	}
}
