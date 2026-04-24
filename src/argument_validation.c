#include "../include/so_long.h"

static int	is_argc_valid(int argc)
{
	if (argc != 2)
		return (write(2, "Error\nUsage: ./so_long <map_file>\n", 34), 0);
	return (1);
}

static int	has_ber_extension(const char *filename)
{
	size_t	i;

	i = ft_strlen(filename);
	if (filename[i - 4] == '.' && \
		filename[i - 3] == 'b' && \
		filename[i - 2] == 'e' && \
		filename[i - 1] == 'r')
		return (1);
	return (write(2, "Error\nInvalid map extension (.ber required)\n", 44), 0);
}

int	validate_args(int argc, char **argv)
{
	return (!is_argc_valid(argc) || !has_ber_extension(argv[1]));
}
