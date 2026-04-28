#include "../include/so_long.h"

#include <X11/keysym.h>

static void	update_player_position(t_data *game, int y, int x)
{
	game->player_y = y;
	game->player_x = x;
	game->step_count++;
}

static void	redraw_player(t_data *game, int old_y, int old_x, int y, int x)
{
	draw_tile(game, old_y, old_x);
	draw_tile(game, y, x);
}

static void	move_player(t_data *game, int y, int x)
{
	int	old_y;
	int	old_x;

	old_y = game->player_y;
	old_x = game->player_x;
	if (game->array[y][x] == '0' || game->array[y][x] == 'C')
	{
		if (game->array[y][x] == 'C')
			game->c_count--;
		game->array[y][x] = 'P';
	}
	if (game->array[old_y][old_x] == 'S')
		game->array[old_y][old_x] = 'E';
	else
		game->array[old_y][old_x] = '0';
	if (game->c_count != 0 && game->array[y][x] == 'E')
		game->array[y][x] = 'S';
	else if (game->c_count == 0 && game->array[y][x] == 'E')
	{
		write(1, "Congratulations, you've finished the game!\n", 44);
		exit_game(game);
	}
	update_player_position(game, y, x);
	redraw_player(game, old_y, old_x, y, x);
	ft_printf("Step Count: %d\n", game->step_count);
}

int	keys(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
	{
		write(1, "Successfully exited after pressing ESC.\n", 41);
		exit_game(game);
	}
	if ((keycode == XK_w || keycode == XK_Up)
		&& game->array_playable[game->player_y - 1][game->player_x] != '1')
		move_player(game, game->player_y - 1, game->player_x);
	if ((keycode == XK_a || keycode == XK_Left)
		&& game->array_playable[game->player_y][game->player_x - 1] != '1')
		move_player(game, game->player_y, game->player_x - 1);
	if ((keycode == XK_s || keycode == XK_Down)
		&& game->array_playable[game->player_y + 1][game->player_x] != '1')
		move_player(game, game->player_y + 1, game->player_x);
	if ((keycode == XK_d || keycode == XK_Right)
		&& game->array_playable[game->player_y][game->player_x + 1] != '1')
		move_player(game, game->player_y, game->player_x + 1);
	return (0);
}
