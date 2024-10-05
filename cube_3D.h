/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:37:35 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/05 17:50:37 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESC 65307

# define WINDOW_Y 500
# define WINDOW_X 500
# define PLAYER_SIZE 9

typedef struct s_map
{
	char	*map_name;
	char	**map;
	int		y;
	int		index;
	int		direction;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_arg
{
	char	**content;
	char	*no_file;
	char	*ea_file;
	char	*we_file;
	char	*so_file;
	t_color	floor;
	t_color	ceiling;
	t_map	s_map;
	int		lines;
}	t_arg;

typedef struct s_player
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	theta;
}	t_player;

typedef struct s_image
{
	void	*image;
	char	*adress;
	int		bits_per_adress;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_cube
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_player	player;

}	t_cube;

int		main(int argc, char **argv);

int		ft_cpy(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	ft_memset(int *tab, int c, size_t size);
int		is_whitespace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	free_str(char **str);

int		file_is_valid(char *file_name);
int		text_utils(char *str);
int		check_file(char *file, t_arg *arg);
int		ft_create_arg(char *file_name, int file_fd, t_arg *arg);
int		ft_fill_arg(char *file_name, int file_fd, t_arg *arg);

int		ft_limits_check(char *str, int tab[6], t_arg *arg);
int		ft_check_color_validity(t_arg *arg);
int		ft_floor_utils(char *nb);
int		ft_fill_utils(char *str);
int		ft_whitespace_utils(char *str);
int		ft_isdigit_utils(char *str);

char	*get_texture_name(char *str, char *texture);
int		ft_is_north(char *str, int tab[6], t_arg *arg);
int		ft_is_east(char *str, int tab[6], t_arg *arg);
int		ft_is_west(char *str, int tab[6], t_arg *arg);
int		ft_is_south(char *str, int tab[6], t_arg *arg);

int		ft_is_valid(char c);
int		ft_nmb_player(char c, int cmp);
int		ft_check_map_walls(char **map);
int		ft_check_valid_map(char *map_name, t_map *s_map);
int		ft_test(void);

#endif
