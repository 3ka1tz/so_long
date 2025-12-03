#include "../include/so_long.h"

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

int	main(int argc, char **argv)
{
	t_data	game;

	validate_arguments(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		return (write(2, "Error!\nUnable to open file.\n", 29), -1);
	game.string_length = count_bytes_from_fd(game.fd);
	game.string = malloc(game.string_length + 1);
	if (!game.string)
		return (write(2, "Error!\nMemory allocation failed.\n", 34), -1);
	close(game.fd);
	game.fd = open(argv[1], O_RDONLY);
	read(game.fd, game.string, game.string_length);
	close(game.fd);
	game.string[game.string_length] = '\0';
	game.array = ft_split(game.string, '\n');
	game.array_playable = ft_split(game.string, '\n');
	init_struct(&game);
	if (is_map_valid(&game))
		init_game(&game);
	else
		free_game_data(&game);
	return (0);
}
