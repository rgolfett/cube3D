#include "cube_3D.h"

t_image	load_img(void *mlx, t_image *wall, char *texture)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	if (!wall)
		printf("wall == NULL\n");
	wall->image = mlx_xpm_file_to_image(mlx, texture, &wall->width, &wall->height);
	printf("%d %d %p\n", wall->width, wall->height, wall->ad);
	if (wall->image)
	{
		wall->ad  = (unsigned int *)
				mlx_get_data_addr(wall->image, &bits_per_pixel, &size_line, &endian);
	}
	if (!wall->image)
		printf("wall->image == NULL\n");
	return (*wall);
}

int	ft_load_sprites(t_cube *cube, t_wall *wall)
{
	wall->north = load_img(cube->mlx, &wall->north, cube->arg.no_file);
	if(!wall->north.image)
		return (1);
	wall->south = load_img(cube->mlx, &wall->south, cube->arg.so_file);
	if(!wall->south.image)
		return (1);
	wall->east = load_img(cube->mlx, &wall->east, cube->arg.ea_file);
	if(!wall->east.image)
		return (1);
	wall->west = load_img(cube->mlx, &wall->west, cube->arg.we_file);
	if(!wall->west.image)
		return (1);
	return (0);
}

void	draw_text_wall(t_cube *data, int x, double height, int side)
{
	double	 i;
	int	y_start;
	int	nb_y_pixel;
	double limit;
	int	text_x = 0;
	int	text_y = 0;

	i = 0;
	nb_y_pixel = (double)WINDOW_Y * height;
	if (height > 1.0f)
	{
		i = (height - 1.0f) * 100 * 4;
		height = 1.0f;
		nb_y_pixel = (double)WINDOW_Y * height + i * 2;
	}
	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
	while (i < nb_y_pixel && y_start <= WINDOW_Y)
	{
		limit = (double)i / (double)nb_y_pixel;
	if (side == 1)
	{
		text_x = data->arg.wall.north.width * data->player.wall_off;
		text_y = data->arg.wall.north.height * limit;
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] 
					= data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x];
	}
	else if (side == 2)
	{
		text_x = data->arg.wall.south.width * data->player.wall_off;
		text_y = data->arg.wall.south.height * limit;
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] 
					= data->arg.wall.south.ad[text_y * data->arg.wall.south.width + text_x];
	}
	else if (side == 3)
	{
		text_x = data->arg.wall.east.width * data->player.wall_off;
		text_y = data->arg.wall.east.height * limit;
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] 
					= data->arg.wall.east.ad[text_y * data->arg.wall.east.width + text_x];
	}
	else  if (side == 4)
	{
		text_x = data->arg.wall.west.width * data->player.wall_off;
		text_y = data->arg.wall.west.height * limit;
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] 
					= data->arg.wall.west.ad[text_y * data->arg.wall.west.width + text_x];
	}
	else 
	{
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] = 0x000000;
	}
		i++;
		y_start++;
	}
}
