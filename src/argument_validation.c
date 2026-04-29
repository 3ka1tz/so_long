// #include "../libft/include/libft.h"
#include "../include/so_long.h"

static int	is_argc_valid(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <map_file>\n", 2);
		return (0);
	}
	return (1);
}

static int	has_ber_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid map extension (.ber required)\n", 2);
		return (0);
	}
	return (1);
}

int	are_args_valid(int argc, char **argv)
{
	if (!is_argc_valid(argc))
		return (0);
	if (!has_ber_extension(argv[1]))
		return (0);
	return (1);
}
