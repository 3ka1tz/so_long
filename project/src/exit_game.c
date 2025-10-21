/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:20:56 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/12 12:07:36 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_mlx_resources(t_data *game)
{
	if (game->_0)
		mlx_destroy_image(game->mlx, game->_0);
	if (game->_1)
		mlx_destroy_image(game->mlx, game->_1);
	if (game->c)
		mlx_destroy_image(game->mlx, game->c);
	if (game->e)
		mlx_destroy_image(game->mlx, game->e);
	if (game->p)
		mlx_destroy_image(game->mlx, game->p);
	if (game->s)
		mlx_destroy_image(game->mlx, game->s);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_game_data(t_data *game)
{
	int	i;

	if (game->string)
		free(game->string);
	i = 0;
	while (game->array[i])
	{
		free(game->array[i]);
		i++;
	}
	i = 0;
	while (game->array_playable[i])
	{
		free(game->array_playable[i]);
		i++;
	}
	free(game->array);
	free(game->array_playable);
}

int	exit_game(t_data *game)
{
	destroy_mlx_resources(game);
	free_game_data(game);
	exit(0);
}
