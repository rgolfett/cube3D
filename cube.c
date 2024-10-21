
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

float	ray(float angle, t_player *player, t_map *map)
{
	float	dir_x;
	float	dir_y;
	float	x_step;
	float	y_step;
	float	x;
	float	y;

	// x = player->spawn_x;
	// y = player->spawn_y;
	x = player->x1;
	y = player->y1;
	dir_x = cosf(angle * MY_PI / 180);
	dir_y = sinf(angle * MY_PI / 180);
	x_step = dir_x / 100;
 	y_step = dir_y / 100;
	while (map->map[(int)y][(int)x] != '1')
	{
		x += x_step;
		y += y_step;
	}
	// x -= player->spawn_x;
	// y -= player->spawn_y;
	x -= player->x1;
	y -= player->y1;
	return (sqrt((x * x) + (y * y)));
}

void	raycasting(t_cube *data)
{
	int		i;
	float	start;
	float	angle;
	float	distance;

	i = 0;
	start = data->player.theta - (float)FOV / 2.0f;
	angle = start;
	while (i < WINDOW_X)
	{
		distance = ray(angle, &data->player, &data->arg.s_map);
		draw_column(data, i, (1.0f / distance), 0, 0);
		angle += (float)FOV / (float)WINDOW_X;
		i++;
	}
}

#include <time.h>
void	ft_display(t_cube *data)
{
	static int		frameCount = 0;
	static clock_t	startTime = 0;
	double			elapsedTime;
	if (startTime == 0)
		startTime = clock();

	deal_key(data);
	fill_background(data);
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