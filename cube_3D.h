#ifndef CUBE_3D_H
# define CUBE_3D_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"


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
	int	y;
	int	index;
}	t_map;

typedef	struct s_arg
{
	char **content;
	char *NO_file;
	char *EA_file;
	char *WE_file;
	char *SU_file;
	char *Roof;
	char *Floor;
	t_map s_map;
	int	h;
}	t_arg;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;


typedef struct s_image
{
	void	*image;
	char	*adress;
	int	bits_per_adress;
	int	size_line;
	int	endian;
}	t_image;

typedef struct s_cube
{
	void	*mlx;
	void	*window;
	t_image	image;
	t_player	player;

}	t_cube;

int main(int argc, char **argv);

int	ft_cpy(char *s1, char *s2);
int	ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *str, int c, size_t size);

int	is_whitespace(int c);

int check_file(char *file, t_arg *arg);
int	ft_create_arg(char *file_name, int file_fd, t_arg *arg);
int	ft_fill_arg(char *file_name, int file_fd, t_arg *arg);
int	ft_is_north(char *str, int tab[4], t_arg *arg);

int	ft_is_valid(char c);
int	ft_nmb_player(char c, int cmp);
int	ft_check_map_walls(char **map);
int	ft_check_valid_map(char *map_name, t_map *s_map);
int	ft_test();


#endif
