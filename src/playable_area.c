/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_area.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:15:58 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/13 12:25:13 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_map_playable(t_data *game)
{
	if (game->array_playable[game->row][game->col - 1] == '1' && \
		game->array_playable[game->row][game->col + 1] == '1' && \
		game->array_playable[game->row - 1][game->col] == '1' && \
		game->array_playable[game->row + 1][game->col] == '1')
	{
		free_game_data(game);
		return (write(2, "Error!\nMap is not playable.\n", 29), 0);
	}
	return (1);
}

static void	initialize_player_position(t_data *game)
{
	game->row = 0;
	while (game->array_playable[game->row])
	{
		game->col = 0;
		while (game->array_playable[game->row][game->col])
		{
			if (game->array_playable[game->row][game->col] == 'P')
			{
				if (is_map_playable(game) == 0)
					exit(1);
				game->player_x = game->row;
				game->player_y = game->col;
				game->array_playable[game->row][game->col] = '-';
				break ;
			}
			game->col++;
		}
		game->row++;
	}
}

static void	update_adjacent_playable_cells(t_data *game)
{
	if (game->array_playable[game->row - 1][game->col] != '1' && \
		game->array_playable[game->row - 1][game->col] != '-')
	{
		game->array_playable[game->row - 1][game->col] = '-';
		game->change = 1;
	}
	if (game->array_playable[game->row + 1][game->col] != '1' && \
		game->array_playable[game->row + 1][game->col] != '-')
	{
		game->array_playable[game->row + 1][game->col] = '-';
		game->change = 1;
	}
	if (game->array_playable[game->row][game->col - 1] != '1' && \
		game->array_playable[game->row][game->col - 1] != '-')
	{
		game->array_playable[game->row][game->col - 1] = '-';
		game->change = 1;
	}
	if (game->array_playable[game->row][game->col + 1] != '1' && \
		game->array_playable[game->row][game->col + 1] != '-')
	{
		game->array_playable[game->row][game->col + 1] = '-';
		game->change = 1;
	}
}

static void	expand_playable_area(t_data *game)
{
	game->change = 0;
	game->row = 0;
	while (game->array_playable[game->row])
	{
		game->col = 0;
		while (game->array_playable[game->row][game->col])
		{
			if (game->array_playable[game->row][game->col] == '-')
				update_adjacent_playable_cells(game);
			game->col++;
		}
		game->row++;
	}
}

int	is_map_winnable(t_data *game)
{
	initialize_player_position(game);
	game->change = 1;
	while (game->change == 1)
		expand_playable_area(game);
	game->row = 0;
	while (game->array_playable[game->row])
	{
		game->col = 0;
		while (game->array_playable[game->row][game->col])
		{
			if (game->array_playable[game->row][game->col] == 'E' || \
				game->array_playable[game->row][game->col] == 'C')
				return (write(1, "Error!\nMap is not winnable.\n", 29), 0);
			game->col++;
		}
		game->row++;
	}
	return (1);
}
