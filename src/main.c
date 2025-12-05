#include "../include/so_long.h"

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
	init_struct(&game);
	read_map_file(&game, argv[1]);
	if (is_map_valid(&game))
		init_game(&game);
	else
		free_game_data(&game);
	return (0);
}
