#include "../include/so_long.h"

#include <unistd.h>

void	load_textures(t_data *game)
{
	int	res;

	res = 100;
	game->_0 = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &res, &res);
	if (!game->_0)
		write(2, "Error\nUnable to load ground texture.\n", 37);
	game->_1 = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &res, &res);
	if (!game->_1)
		write(2, "Error\nUnable to load wall texture.\n", 35);
	game->c = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm", &res, &res);
	if (!game->c)
		write(2, "Error\nUnable to load collectible texture.\n", 42);
	game->e = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm", &res, &res);
	if (!game->e)
		write(2, "Error\nUnable to load exit texture.\n", 35);
	game->p = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm", &res, &res);
	if (!game->p)
		write(2, "Error\nUnable to load player texture.\n", 37);
	game->s = mlx_xpm_file_to_image(game->mlx, "textures/S.xpm", &res, &res);
	if (!game->s)
		write(2, "Error\nUnable to load player above exit texture.\n", 48);
	if (!game->_0 || !game->_1 || !game->c || !game->e || !game->p || !game->s)
		exit_game(game);
}

void	draw_tile(t_data *game, int y, int x)
{
	if (game->array[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->_0, x * 100, y * 100);
	else if (game->array[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->_1, x * 100, y * 100);
	else if (game->array[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->c, x * 100, y * 100);
	else if (game->array[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->e, x * 100, y * 100);
	else if (game->array[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->p, x * 100, y * 100);
	else if (game->array[y][x] == 'S')
		mlx_put_image_to_window(game->mlx, game->win, \
								game->s, x * 100, y * 100);
}

int	draw_map(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
