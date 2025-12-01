#include "../include/so_long.h"

static void	validate_number_of_arguments(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

static char	*str_to_lowercase(const char *s)
{
	char	*result;
	size_t	i;

	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = tolower((unsigned char)s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	validate_map_file_extension(const char *filename)
{
	char	*lowercase_filename;
	char	*extension;

	lowercase_filename = str_to_lowercase(filename);
	extension = ft_strrchr(lowercase_filename, '.');
	if (!extension || ft_strcmp(extension, ".ber") != 0)
	{
		ft_putstr_fd("Error\nInvalid map file extension\n", 2);
		free(lowercase_filename);
		exit(EXIT_FAILURE);
	}
	free(lowercase_filename);
}

void	validate_input(int argc, char **argv)
{
	validate_number_of_arguments(argc);
	validate_map_file_extension(argv[1]);
}
