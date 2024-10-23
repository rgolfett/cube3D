/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:37:35 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 13:55:32 by rgolfett         ###   ########lyon.fr   */
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
# define KEY_SHIFT 65505

# define MY_PI 3.14159265358979323846
# define INV_180 (1.0 / 180.0)

# define WINDOW_X 1920
# define WINDOW_Y 860
# define PLAYER_SIZE 9
# define STEP_SIZE 0.01
# define RAY_NB 360

# define FOV 90
# define SPEED 0.03
# define ROTATION_SPEED 0.1


typedef struct s_key
{
	int	press_w;
	int	press_a;
	int	press_s;
	int	press_d;
	int	look_right;
	int	look_left;
}	t_key;

typedef struct s_image
{
	void	*image;
	char	*address;
	int		*ad;
	int		bits_per_address;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_wall
{
	t_image	north;
	t_image	east;
	t_image	west;
	t_image	south;
}	t_wall;

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
	t_wall	wall;
	t_key	m_key;
	int		lines;
	int	h;
	double	zoom;
	double	coef_zoom;
}	t_arg;

typedef struct s_player
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	theta;
	int		spawn_x;
	int		spawn_y;
	double	x_pos_map;
	double	y_pos_map;
	int		sprint;
	double	wall_off;
	double	height;
	int		orientation;
	double	dir_x;
	double	dir_y;
}	t_player;


typedef struct s_cube
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_player	player;
	t_arg		arg;
	int			ray_color;
	int			ceiling_color;
	int			floor_color;
	double		axes_mul;
	double		head;
	double		band_w;
	double		incr;
	int			show_fps;
	double		end_axes;
	int			mid_x;
	int			mid_y;
	int 		old_mouse_x;
	int 		old_mouse_y;
	int			x;
}	t_cube;

int		main(int argc, char **argv);

int		ft_cpy(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	ft_memset(int *tab, int c, size_t size);
int		is_whitespace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	free_str(char **str);
void	free_utils(t_arg *arg);

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
//int		ft_test(void);
int		deal_key(t_cube *data);

void	ft_raycasting(t_arg arg);
int		deal_mouse(int button, int x, int y, t_cube *data);
void	ft_pixel_put(t_cube *data, int x, int y, int color);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	draw_texture(int x, int y, t_cube *data);
void	draw_utils(double x1, double y1, double x2, double y2, t_cube *data);

int	ft_load_sprites(t_cube *cube, t_wall *wall);
//void 	tmp_raycast(t_cube *data);

void fill_background(t_cube *data);
void	ft_cube(t_arg arg);
void	raycasting(t_cube *data);
void	draw_column(t_cube *data, int x, double height, int side, double wall_off);
void	draw_text_wall(t_cube *data, int x, double height, int side);

void	init_data(t_cube *data, t_arg arg);

int		ft_display(t_cube *data);
int		move_key(int key, t_cube *data);
int		move_key_zero(int key, t_cube *data);
int		move_mouse(t_cube *data);

void	move_front(t_cube *data);
void	move_back(t_cube *data);
void	move_left(t_cube *data);
void	move_right(t_cube *data);

#endif