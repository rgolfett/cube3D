/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:39:42 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/23 13:51:53 by kiparis          ###   ########.fr       */
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
	if (diff_wall_x < 0.01 && diff_wall_y < 0.01)
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
		distance = ray(angle, &data->player, &data->arg.s_map);
		draw_text_wall(data, i, (1.0f / distance), data->player.orientation);
		angle += (double)FOV / (double)WINDOW_X;
		i++;
	}
}

int	ft_display(t_cube *data)
{
	deal_key(data);
	move_mouse(data);
	fill_background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}
