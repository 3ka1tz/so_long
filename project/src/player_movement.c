/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:47:44 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/21 11:25:08 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "../include/so_long.h"

static void	update_player_position(t_data *game, int y, int x)
{
	game->player_y = y;
	game->player_x = x;
	game->step_count++;
}

static void	redraw_player(t_data *game, int old_position[2], int y, int x)
{
	draw_tile(game, old_position[0], old_position[1]);
	draw_tile(game, y, x);
}

static void	move_player(t_data *game, int y, int x)
{
	int	old_position[2];

	old_position[0] = game->player_y;
	old_position[1] = game->player_x;
	if (game->array[y][x] == 'C')
	{
		game->array[y][x] = 'P';
		game->c_count--;
	}
	else if (game->array[y][x] == '0')
		game->array[y][x] = 'P';
	if (game->array[old_position[0]][old_position[1]] == 'S')
		game->array[old_position[0]][old_position[1]] = 'E';
	else
		game->array[old_position[0]][old_position[1]] = '0';
	if (game->c_count != 0 && game->array[y][x] == 'E')
		game->array[y][x] = 'S';
	else if (game->c_count == 0 && game->array[y][x] == 'E')
	{
		write(1, "Congratulations, you've finished the game!\n", 44);
		exit_game(game);
	}
	update_player_position(game, y, x);
	redraw_player(game, old_position, y, x);
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
