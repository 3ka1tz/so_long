#include "../include/so_long.h"
#include <stdlib.h>

static int	count_bytes_from_fd(int fd)
{
	char	buffer[1];
	int		bytes_read;
	int		total_bytes;

	total_bytes = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
			return (total_bytes);
		if (bytes_read == 0)
			break ;
		total_bytes += bytes_read;
	}
	return (total_bytes);
}

static void	init_struct(t_data *game)
{
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->step_count = 0;
	game->flag = 0;
}

static int	init_game(t_data *game)
{
	int	x;
	int	y;

	x = game->width;
	y = game->height;
	write(1, "Collect every coin and reach the exit.\n", 40);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x * 100, y * 100, "so_long");
	load_textures(game);
	draw_map(game);
	mlx_key_hook(game->win, keys, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

static char	*read_map(const char *file)
{
	int		fd;
	size_t	size;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nUnable to open input map file\n", 36), NULL);
	size = count_bytes_from_fd(fd);
	close(fd);
	if (size == 0)
		return (write(2, "Error\nEmpty map\n", 16), NULL);
	str = malloc(size + 1);
	if (!str)
		return (write(2, "Error\nMap string allocation failed\n", 35), NULL);
	fd = open(file, O_RDONLY);
	read(fd, str, size);
	str[size] = '\0';
	close(fd);
	return (str);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (!are_args_valid(argc, argv))
		return (1);
	game.map_str = read_map(argv[1]);
	if (!game.map_str)
		return (1);
	game.array = ft_split(game.map_str, '\n');
	game.array_playable = ft_split(game.map_str, '\n');
	init_struct(&game);
	if (is_map_valid(&game))
		init_game(&game);
	else
		free_game_data(&game);
	return (0);
}
