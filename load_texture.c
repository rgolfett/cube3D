#include "cube_3D.h"

t_image	load_img(void *mlx, t_image *wall, char *texture)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	
	if (!wall)
		printf("aaaa\n");
	wall->image = mlx_xpm_file_to_image(mlx, texture, &wall->width, &wall->height);
	printf("%d %d %p\n", wall->width, wall->height, wall->ad);
	if (wall->image)
	{
		wall->ad  = (unsigned int *)
				mlx_get_data_addr(wall->image, &bits_per_pixel, &size_line, &endian);
	}
	if (!wall->image)
		printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	return (*wall);
}


int	ft_load_sprites(t_cube *cube, t_image *wall)
{
	// *wall = load_img(cube->mlx, wall, "touch-grass.xpm");
	*wall = load_img(cube->mlx, wall, "socks.xpm");
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

void	draw_texture(int x, int y, t_cube *data)
{
	draw_wall(x, y, data, &data->arg.wall.north);
}
