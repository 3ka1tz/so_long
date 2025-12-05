#include "../include/so_long.h"

#include <stdio.h>

#define BUFFER_SIZE 4096

static ssize_t	count_file_bytes(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	tmp;
	ssize_t	total;

	total = 0;
	while (1)
	{
		tmp = read(fd, buf, BUFFER_SIZE);
		if (tmp == -1)
		{
			ft_putendl_fd("Error", 2);
			perror("read");
			return (-1);
		}
		if (tmp == 0)
			break ;
		total += tmp;
	}
	return (total);
}

void	read_map_file(t_data *game, char *file)
{
	int		fd;
	ssize_t	size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror("open");
		exit(EXIT_FAILURE);
	}
	size = count_file_bytes(fd);
	close(fd);
	game->string = malloc(size + 1);
	if (!game->string)
	{
		ft_putendl_fd("Error", 2);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	read(fd, game->string, size);
	close(fd);
	game->string[size] = '\0';
	game->array = ft_split(game->string, '\n');
	game->array_playable = ft_split(game->string, '\n');
}
