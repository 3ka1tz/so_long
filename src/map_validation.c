#include "../include/so_long.h"

#include <unistd.h>

static int	are_chars_valid(t_data *game)
{
	size_t	i;

	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] != '0' && \
			game->map_str[i] != '1' && \
			game->map_str[i] != 'C' && \
			game->map_str[i] != 'E' && \
			game->map_str[i] != 'P' && \
			game->map_str[i] != '\n')
		{
			write(2, "Error\nMap has invalid characters\n", 33);
			return (0);
		}
		if (game->map_str[i] == '\n' && game->map_str[i + 1] == '\n')
		{
			write(2, "Error\nMap has consecutive linefeeds\n", 36);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	are_enough_elements(t_data *game)
{
	size_t	i;

	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] == 'C')
			game->c_count++;
		if (game->map_str[i] == 'E')
			game->e_count++;
		if (game->map_str[i] == 'P')
			game->p_count++;
		i++;
	}
	if (game->c_count < 1)
		return (write(2, "Error\nNo C in map\n", 18), 0);
	if (game->e_count == 0)
		return (write(2, "Error\nNo E in map\n", 18), 0);
	if (game->e_count > 1)
		return (write(2, "Error\nMultiple E in map\n", 24), 0);
	if (game->p_count <= 0)
		return (write(2, "Error\nNo P in map\n", 18), 0);
	if (game->p_count > 1)
		return (write(2, "Error\nMultiple P in map\n", 24), 0);
	return (1);
}

static int	is_map_rectangular(t_data *game)
{
	size_t	i;

	game->width = ft_strlen(game->array[0]);
	i = 1;
	while (game->array[i])
	{
		if (ft_strlen(game->array[i]) != game->width)
			return (write(2, "Error\nMap must be rectangular.\n", 31), 0);
		i++;
	}
	return (1);
}

static int	is_map_enclosed(t_data *game)
{
	check_top_bottom_rows(game);
	check_left_right_columns(game);
	if (game->flag == 1)
		return (write(2, "Error\nMap must be enclosed by walls.\n", 37), 0);
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
