/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:18:42 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/11 10:31:27 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_height(t_data *game)
{
	int	i;

	i = 0;
	while (game->array[i])
		i++;
	return (i);
}

void	check_top_bottom_rows(t_data *game)
{
	int	i;

	i = 0;
	while (game->array[0][i])
	{
		if (game->array[0][i++] != '1')
		{
			write(2, "Top row is not enclosed.\n", 26);
			game->flag = 1;
		}
	}
	i = 0;
	game->height = get_map_height(game);
	while (game->array[game->height - 1][i])
	{
		if (game->array[game->height - 1][i++] != '1')
		{
			write(2, "Bottom row is not enclosed.\n", 29);
			game->flag = 1;
		}
	}
}

void	check_left_right_columns(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->array[i][0] != '1')
		{
			write(2, "Left column is not enclosed.\n", 30);
			game->flag = 1;
		}
		if (game->array[i][game->width - 1] != '1')
		{
			write(2, "Right column is not enclosed.\n", 31);
			game->flag = 1;
		}
		i++;
	}
}
