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


int	ft_load_sprites(t_cube *cube, t_image *wall)
{
	//*wall = load_img(cube->mlx, wall, "touch-grass.xpm");
	*wall = load_img(cube->mlx, wall, "socks.xpm");
	//*wall = load_img(cube->mlx, wall, "jesus.xpm");
	
	return (0);
}

void	draw_wall(int x, int y, t_cube *data, t_image *wall)
{
	int	i;
	int tmp;

	i = 0;
	tmp = x;
	while (wall->width * wall->height > i)
	{
		ft_pixel_put(data, x, y, wall->ad[i]);
		x++;
		if ((x - tmp) == wall->width)
		{
			y++;
			x = tmp;
		}
		i++;
		printf("i = %i\n", i);
	}
}
// void	draw_text_wall(t_cube *data, int x, double height, int side, double wall_off)
// {
// 	int	 i;
// 	int	y_start;
// 	int	nb_y_pixel;
// 	double limit;
// 	int	text_x = 0;
// 	int	text_y = 0;

// 	i = 0;
// 	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
// 	nb_y_pixel = WINDOW_Y * height;
// 	{
// 		limit = (double)i / (double)nb_y_pixel;
// 		text_x = data->arg.wall.north.width * wall_off;
// 		text_y = data->arg.wall.north.height * limit;
// 		// ajouter les points cardinaux
// 		my_mlx_pixel_put(&data->image, x, y_start,
// 			data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x]);
// 		i++;
// 		y_start++;
// 	}
// }

void	draw_texture(int x, int y, t_cube *data)
{
	draw_wall(x, y, data, &data->arg.wall.north);
}

void	draw_text_wall(t_cube *data, int x, double height, int side, double wall_off)
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
		text_x = data->arg.wall.north.width * wall_off;
		text_y = data->arg.wall.north.height * limit;
		// ajouter les points cardinaux
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] 
					= data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x];
		// my_mlx_pixel_put(&data->image, x, y_start,
		// 	data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x]);
		// ((unsigned int*)(data->image.address))[y_start * data->image.width + x] = 0;
		i++;
		y_start++;
	}
}

void	draw_column(t_cube *data, int x, double height, int side, double wall_off)
{
	int	 i;
	int	y_start;
	int	nb_y_pixel;
	double limit;

	if (height > 1.0f)
		height = 1.0f;
	i = 0;
	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
	nb_y_pixel = (double)WINDOW_Y * height;
	
	while (i < nb_y_pixel)
	{
		limit = (double)i / (double)nb_y_pixel;
	//	printf("limit = %f\n", limit)
		((unsigned int*)(data->image.address))[y_start * data->image.width + x] = 0;
		// if (y_start >= 0 && y_start < data->image.height)
			// my_mlx_pixel_put(&data->image, x, y_start, 0x0);
			//my_mlx_pixel_put(&data->image, x, y_start, ((int)(red * limit) & 0xff0000) + blue * wall_off);
		//data->arg.wall.north.ad[i]
		i++;
		y_start++;
	}
}

void 	tmp_raycast(t_cube *data)
{
	//fill_background(data);
	
	enum {
		EAST,
		SOUTH,
		WEST,
		NORTH,
	}	side_e;

	struct {
		double height;
		int side;
		double wall_off;
	}	rays[WINDOW_X];

	int i = 0;
	for (; i < WINDOW_X / 2; i++)
	{
		rays[i].height = 1.0f - ((double)i / (double)WINDOW_X);
		rays[i].side = EAST;
		rays[i].wall_off = (double)i / (double)WINDOW_X * 2;
	}
	for (; i < WINDOW_X; i++)
	{
		rays[i].height = (double)i / (double)WINDOW_X;
		rays[i].side = SOUTH;
		rays[i].wall_off = ((double)i / (double)WINDOW_X - 0.5f) * 2;
	}
	
	for (int x = 0; x < sizeof(rays) / sizeof(*rays); x++)
		draw_text_wall(data, x, rays[x].height, rays[x].side, rays[x].wall_off);
}