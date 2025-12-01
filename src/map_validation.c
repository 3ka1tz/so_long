/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:46:51 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/21 12:23:43 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	are_chars_valid(t_data *game)
{
	int	i;

	i = 0;
	if (!game->string[i])
		return (write(2, "Error!\nMap is empty.\n", 22), 0);
	while (game->string[i])
	{
		if (game->string[i] != '0' && \
			game->string[i] != '1' && \
			game->string[i] != 'C' && \
			game->string[i] != 'E' && \
			game->string[i] != 'P' && \
			game->string[i] != '\n')
			return (write(2, "Error!\nMap has invalid characters.\n", 36), 0);
		if (game->string[i] == '\n' && game->string[i + 1] == '\n')
		{
			write(2, "Error!\nMap has consecutive linefeeds.\n", 39);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	are_enough_elements(t_data *game)
{
	int	i;

	i = 0;
	while (game->string[i])
	{
		if (game->string[i] == 'C')
			game->c_count++;
		if (game->string[i] == 'E')
			game->e_count++;
		if (game->string[i] == 'P')
			game->p_count++;
		i++;
	}
	if (game->c_count < 1)
		return (write(2, "Error!\nNo C in map.\n", 21), 0);
	if (game->e_count == 0)
		return (write(2, "Error!\nNo E in map.\n", 21), 0);
	if (game->e_count > 1)
		return (write(2, "Error!\nMultiple E in map.\n", 27), 0);
	if (game->p_count <= 0)
		return (write(2, "Error!\nNo P in map.\n", 21), 0);
	if (game->p_count > 1)
		return (write(2, "Error!\nMultiple P in map.\n", 27), 0);
	return (1);
}

static int	is_map_rectangular(t_data *game)
{
	int	i;

	game->width = ft_strlen(game->array[0]);
	i = 1;
	while (game->array[i])
	{
		if (ft_strlen(game->array[i]) != (size_t)game->width)
			return (write(2, "Error!\nMap must be rectangular.\n", 33), 0);
		i++;
	}
	return (1);
}

static int	is_map_enclosed(t_data *game)
{
	check_top_bottom_rows(game);
	check_left_right_columns(game);
	if (game->flag == 1)
		return (write(2, "Error!\nMap must be enclosed by walls.\n", 39), 0);
	return (1);
}

int	is_map_valid(t_data *game)
{
	if (!are_chars_valid(game) || \
		!are_enough_elements(game) || \
		!is_map_rectangular(game) || \
		!is_map_enclosed(game) || \
		!is_map_winnable(game))
		return (0);
	return (1);
}
