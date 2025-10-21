/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:12:03 by elopez-u          #+#    #+#             */
/*   Updated: 2025/02/13 12:25:35 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "../minilibx-linux/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		string_length;
	char	*string;
	char	**array;
	char	**array_playable;
	int		fd;
	int		c_count;
	int		e_count;
	int		p_count;
	int		width;
	int		height;
	int		col;
	int		row;
	int		change;
	int		player_x;
	int		player_y;
	void	*img;
	void	*_0;
	void	*_1;
	void	*c;
	void	*e;
	void	*p;
	void	*s;
	int		step_count;
	int		flag;
}	t_data;

int		ft_strlen(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	**ft_split(const char *s, char c);

int		ft_printnbr_recursive(unsigned int n);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printhex(unsigned int n, int lower_upper);
int		ft_printptr(void *ptr);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_handle_specifier(const char **format, va_list args);
int		ft_process_format(const char *format, va_list args);
int		ft_printf(const char *format, ...);

void	validate_map_file(char **argv);
void	check_top_bottom_rows(t_data *game);
void	check_left_right_columns(t_data *game);
int		is_map_valid(t_data *game);
int		is_map_winnable(t_data *game);
void	load_textures(t_data *game);
void	draw_tile(t_data *game, int y, int x);
int		draw_map(t_data *game);
int		keys(int keycode, t_data *game);
void	free_game_data(t_data *game);
int		exit_game(t_data *game);

#endif