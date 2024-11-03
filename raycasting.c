/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:39:42 by kiparis           #+#    #+#             */
/*   Updated: 2024/11/03 19:19:29 by rgolfett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	fill_background(t_cube *data)
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

int	find_wall_orientation(double x, double y, t_player *player)
{
	double	diff_wall_x;
	double	diff_wall_y;

	diff_wall_x = fabs(x - round(x));
	diff_wall_y = fabs(y - round(y));
	if (diff_wall_x < 0.005 && diff_wall_y < 0.005)
		return (0);
	if (diff_wall_x > diff_wall_y)
	{
		if (player->dir_y <= 0)
			return (player->wall_off = (fabs(x) - abs((int)x)) * \
				(fabs(y) - abs((int)y)), 1);
		else
			return (player->wall_off = (fabs(x) - fabs(ceil(x))) * \
				(fabs(y) - fabs(ceil(y))), 2);
	}
	else
	{
		if (player->dir_x >= 0)
			return (player->wall_off = 1 - (fabs(x) - fabs(ceil(x))) * \
				(fabs(y) - fabs(ceil(y))), 3);
		else
			return (player->wall_off = 1 - (fabs(x) - abs((int)x)) * \
				(fabs(y) - abs((int)y)), 4);
	}
}

double	ray(double angle, t_player *player, t_map *map)
{
	double	x_step;
	double	y_step;
	double	x;
	double	y;

	x = player->x1;
	y = player->y1;
	player->dir_x = cosf(angle * MY_PI / 180);
	player->dir_y = sinf(angle * MY_PI / 180);
	x_step = player->dir_x / 300;
	y_step = player->dir_y / 300;
	while (map->map[(int)y][(int)x] != '\n' && map->map[(int)y][(int)x]
		!= '1' && map->map[(int)y][(int)x])
	{
		x += x_step;
		y += y_step;
	}
	player->orientation = find_wall_orientation(x, y, player);
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
		data->x_line = i;
		distance = ray(angle, &data->player, &data->arg.s_map);
		draw_text_wall(data, (1.0f / distance), data->player.orientation);
		angle += (double)FOV / (double)WINDOW_X;
		i++;
	}
}

void	pause_screen(t_cube *data)
{
	int	i;
	int	nb_pixel;
	float x = 0;
	float y = 0;

	i = 0;
	nb_pixel = WINDOW_X * WINDOW_Y;
	if (data->arg.wall.pause.image == NULL)
	{
		while (i < nb_pixel)
		{
			data->image.ad[i] = 0x666666;
			i++;
		}
	}
	else
	{
		while (i < nb_pixel)
		{
			float x1 = (float)data->arg.wall.pause.width / WINDOW_X;
			float y1 = (float)data->arg.wall.pause.height / WINDOW_Y;
			float img_pxl = ((float)data->arg.wall.pause.width * (float)data->arg.wall.pause.height);
			float ratio = (img_pxl / (float)nb_pixel);
		
			// float w = (float)data->arg.wall.pause.width * x;
			// float h = (float)data->arg.wall.pause.height * y;
			// float w = (float)data->arg.wall.pause.width * ratio;
			// float h = (float)data->arg.wall.pause.height * ratio;
			// float w = (float)x * ratio;
			// float h = (float)y * ratio;
			// printf("w = %f, h = %f\n", w, h);
			//printf("ratio = %f\n", ratio);
			//printf("ratio i = %i\n", (int)(i * ratio));
			//printf("x = %li, y = %li\n", (int)((i / WINDOW_X) * x, (int)((i % WINDOW_Y) * y)));
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)((i / WINDOW_X) * x) * WINDOW_X  + (int)((i / WINDOW_Y) * y)];
			// if (i < data->arg.wall.pause.width * data->arg.wall.pause.height)
			// {
			// 	data->image.ad[i] = data->arg.wall.pause.ad[i];
			// }
			// else
			// 	data->image.ad[i] = 0x111166;
			//printf("i = %i, index = %i\n", i, (int)(i * x + y));
			
		//data->image.ad[i] = data->arg.wall.pause.ad[(int)i * (int)y1 + (int)x1];
			
		//	data->image.ad[i] = data->arg.wall.pause.ad[(int)i * (int)x1 + (int)y1];
			
		data->image.ad[i] = data->arg.wall.pause.ad[(int)((float)i * ratio)];//
			//printf("nb = %f\n", ((float)i / nb_pixel));
		//	printf("nb = %f\n", ((float)i * ratio));
		//data->image.ad[i] = data->arg.wall.pause.ad[(int)((float)i * y1) + (int)(x1)];
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)((y * y1) * (x * x1))];
			//printf("nb = %f\n", (y * y1) * (x * x1));
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)(y) + (int)x];
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)(i * ratio)];
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)(i * h + x)];
			//data->image.ad[i] = data->arg.wall.pause.ad[(int)(i * h + i * w)];
					//printf("nb = %i\n", nb_pixel);	
	//printf("w = %i, h = %i\n", data->arg.wall.pause.width, data->arg.wall.pause.height);
			// printf("x = %f, y = %f\n", x, y);
			// printf("ratio = %i\n", (int)(y * y1) + (int)x);
		// ((unsigned int*)(data->image.ad))[(int)y * data->image.width + data->x_line] = \ 
		// 		data->arg.wall.pause.ad[(int)y1 * data->arg.wall.pause.width + 1];
			i++;
			y++;
		//i = 598572, index = 425984
		//i = 598572, index = 425984
			if (y == WINDOW_Y)
				{
					y = 0;
					x++;
				}
			//printf("x = %f, y = %f\n", x, y);
		}	
	}
}

int	ft_display(t_cube *data)
{
	deal_key(data);
	if (!data->pause_mode)
	{
		move_mouse(data);
		fill_background(data);
		raycasting(data);
	}
	else
		pause_screen(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}
