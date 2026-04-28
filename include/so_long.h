#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
char	**ft_split(const char *s, char c);

int		are_args_valid(int argc, char **argv);
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
