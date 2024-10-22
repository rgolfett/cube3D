
#include "cube_3D.h"

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

void	find_wall_orientation(double x, double y, double dir_x, double dir_y, t_player *player)
{
	double	diff_wall_x = fabs(x - round(x));
	double	diff_wall_y = fabs(y - round(y));

	if (diff_wall_x > diff_wall_y)
	{
		if (dir_y < 0)
			player->wall_off = (fabs(x) - abs((int)x)) * (fabs(y) - abs((int)y)); // nord
		else 
			player->wall_off = (fabs(x) - fabs(ceil(x))) * (fabs(y) - fabs(ceil(y))); // sud
	}
	else 
	{
		if (dir_x > 0)
			player->wall_off = 1 - (fabs(x) - fabs(ceil(x))) * (fabs(y) - fabs(ceil(y))); // est
		else 
			player->wall_off = 1 - (fabs(x) - abs((int)x)) * (fabs(y) - abs((int)y)); // ouest
	}
}

void	wall_point(double angle, double *x, double *y, t_map *map)
{
	double	dir_x;
	double	dir_y;
	double	x_step;
	double	y_step;
	double	diff_x;
	double	diff_y;

	dir_x = cosf(angle * MY_PI / 180);
	dir_y = sinf(angle * MY_PI / 180);
	// x_step = dir_x / 10;
 	// y_step = dir_y / 10;
	diff_x = fabs(*x - round(*x));
	diff_y = fabs(*y - round(*y));
	while (map->map[(int)*y][(int)*x] && map->map[(int)*y][(int)*x] != '1')
	{
		if (diff_x > 0.1 && diff_y > 0.1)
		{
			x_step = dir_x / 10;
 			y_step = dir_y / 10;	
		}
		else 
		{
			x_step = dir_x / 1000;
 			y_step = dir_y / 1000;
		}
		*x += x_step;
		*y += y_step;
		diff_x = fabs(*x - round(*x));
		diff_y = fabs(*y - round(*y));
	}
}

double	ray(double angle, t_player *player, t_map *map)
{
	double	dir_x;
	double	dir_y;
	double	x;
	double	y;

	x = player->x1;
	y = player->y1;
	dir_x = cosf(angle * MY_PI / 180);
	dir_y = sinf(angle * MY_PI / 180);
	wall_point(angle, &x, &y, map);
	
	// while (map->map[(int)y][(int)x] && map->map[(int)y][(int)x] != '1')
	// {
	// 	x += x_step;
	// 	y += y_step;
	// }
	// x -= x_step;
	// y -= y_step;
	// x_step = dir_x / 100;
 	// y_step = dir_y / 100;
	// while (map->map[(int)y][(int)x] && map->map[(int)y][(int)x] != '1')
	// {
	// 	x += x_step;
	// 	y += y_step;
	// }
	// x -= x_step;
	// y -= y_step;
	// x_step = dir_x / 1000;
 	// y_step = dir_y / 1000;
	// while (map->map[(int)y][(int)x] && map->map[(int)y][(int)x] != '1')
	// {
	// 	x += x_step;
	// 	y += y_step;
	// }
	find_wall_orientation(x, y, dir_x, dir_y, player);
	// printf("x = %f, int x = %d, y = %f, int y = %d\n", x, (int)x, y, (int)y);
	// printf("dir_x = %f, dir_y = %f\n", dir_x, dir_y);
	x -= player->x1;
	y -= player->y1;
	// player->wall_off = fabs(((fabs(x) - abs((int)x)) + (fabs(y) - abs((int)y))) / 2);
	// printf("wall = %f\n", player->wall_off);
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
		draw_text_wall(data, i, (1.0f / distance), 0, data->player.wall_off);
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
	ft_load_sprites(&data, &data.arg.wall.north);// a modifier-> load all textures
	mlx_loop_hook(data.mlx, ft_display, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.image.image);
	// mlx_clear_window();
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}