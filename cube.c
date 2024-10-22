
#include "cube_3D.h"

void	get_wall_direction(t_cube *data)
{

}

void fill_background(t_cube *data)
{
	int	half_window;
	int	i;

	half_window = (WINDOW_X * WINDOW_Y) / 2;
	i = 0;
	while (i < half_window)
	{
		data->image.ad[i] = data->arg.ceiling.color;
		i++;
	}
	half_window *= 2;
	while (i < half_window)
	{
		data->image.ad[i] = data->arg.floor.color;
		i++;
	}
}

int	find_wall_orientation(double x, double y, double dir_x, double dir_y, t_player *player)
{
	double	diff_wall_x = fabs(x - round(x));
	double	diff_wall_y = fabs(y - round(y));

	if (diff_wall_x > diff_wall_y)
	{
		// horizontal
		if (dir_y < 0)
		{
			player->wall_off = (fabs(x) - abs((int)x)) * (fabs(y) - abs((int)y)); // nord
			return (1);
		}
		else 
		{
			player->wall_off = (fabs(x) - fabs(ceil(x))) * (fabs(y) - fabs(ceil(y))); // sud
			return (2);
		}
	}
	else 
	{
		// vertical
		if (dir_x > 0)
		{
			player->wall_off = 1 - (fabs(x) - fabs(ceil(x))) * (fabs(y) - fabs(ceil(y))); // est
			return (3);
		}
		else 
		{
			player->wall_off = 1 - (fabs(x) - abs((int)x)) * (fabs(y) - abs((int)y)); // ouest
			return (4);
		}
	}
	return (0);
}

double	ray(double angle, t_player *player, t_map *map)
{
	double	dir_x;
	double	dir_y;
	double	x_step;
	double	y_step;
	double	x;
	double	y;

	x = player->x1;
	y = player->y1;
	dir_x = cosf(angle * MY_PI / 180);
	dir_y = sinf(angle * MY_PI / 180);
	x_step = dir_x / 300;
 	y_step = dir_y / 300;
	while (map->map[(int)y][(int)x] && map->map[(int)y][(int)x] != '1')
	{
		x += x_step;
		y += y_step;
	}
	find_wall_orientation(x, y, dir_x, dir_y, player);
	x -= player->x1;
	y -= player->y1;
	return (sqrt((x * x) + (y * y)));
}

void	raycasting(t_cube *data)
{
	int		i;
	double	start;
	double	angle;
	double	distance;

	i = 0;
	start = data->player.theta - (double)FOV / 2.0f;
	angle = start;
	while (i < WINDOW_X)
	{
		distance = ray(angle, &data->player, &data->arg.s_map);
		draw_text_wall(data, i, (1.0f / distance), 0, fabs(data->player.wall_off));
		//draw_column(data, i, (1.0f / distance), 0, 0);
		angle += (double)FOV / (double)WINDOW_X;
		i++;
	}
}

#include <time.h>

int	ft_display(t_cube *data)
{
	static int		frameCount = 0;
	static clock_t	startTime = 0;
	double			elapsedTime;
	if (startTime == 0)
		startTime = clock();

	deal_key(data);
	move_mouse(data);
	fill_background(data);
	// tmp_raycast(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);

	frameCount++;
	elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
	if (elapsedTime >= 1.0)
	{
		printf("FPS: %d\n", frameCount);
		frameCount = 0;
		startTime = clock();
	}
}

void	ft_cube(t_arg arg)
{
	t_cube	data;

	data.mlx = mlx_init();
	init_data(&data, arg);
	data.window = mlx_new_window(data.mlx, WINDOW_X, \
								WINDOW_Y, "Cube_3D");
	mlx_hook(data.window, 2, 1, deal_key, &data);
	mlx_hook(data.window, 17, 0, mlx_loop_end, data.mlx);
	ft_load_sprites(&data, &data.arg.wall);// a modifier-> load all textures
	mlx_loop_hook(data.mlx, ft_display, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.image.image);
	// mlx_clear_window();
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}