/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:00:36 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/15 14:38:52 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"


void	fill_background(t_cube *data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= data->head)
	{
		x = 0;
		while (x <= WINDOW_X)
		{
			my_mlx_pixel_put(&(data)->image, x, y, data->arg.ceiling.color);
			x++;
		}
		y++;
	}
	while (y <= WINDOW_Y)
	{
		x = 0;
		while (x <= WINDOW_X)
		{
			my_mlx_pixel_put(&(data)->image, x, y, data->arg.floor.color);
			x++;
		}
		y++;
	}
}

void	calc_end_axes(t_cube *data, double *tmp_x, double *tmp_y, double ray_num)
{
	// double	end_axes;
	double	theta;

	// end_axes = 0;
	data->end_axes = 0;
	theta = (data->player.theta + ray_num - FOV * 0.5) * INV_180 * MY_PI;
	while (1)
	{
		*tmp_x = data->player.x_pos_map + data->end_axes * cos(theta);
		*tmp_y = data->player.y_pos_map + data->end_axes * sin(theta);
		if (!data->arg.s_map.map[(int)*tmp_y][(int)*tmp_x] || \
		data->arg.s_map.map[(int)*tmp_y][(int)*tmp_x] == '1')
			break;
		data->end_axes += STEP_SIZE * data->axes_mul;
	}
}

void	algo_ray_end(t_cube *data, double ray_num)
{
	double	tmp_x;
	double	tmp_y;

	data->player.x_pos_map = data->player.x1 * data->arg.coef_zoom;
	data->player.y_pos_map = data->player.y1 * data->arg.coef_zoom;
	data->axes_mul = 100;
	while (data->axes_mul >= 1)
	{
		calc_end_axes(data, &tmp_x, &tmp_y, ray_num);
		data->axes_mul *= 0.1;
	}
	data->player.x2 = tmp_x * data->arg.zoom;
	data->player.y2 = tmp_y * data->arg.zoom;
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

double	calc_incr(int x1, int y1, int x2, int y2, int option)
{
	double	dx;
	double	dy;
	double	steps;

	dx = x2 - x1;
	dy = y2 - y1;
	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	if (option == 1)
		return (dx / steps);
	else if (option == 2)
		return (dy / steps);
	else
		return (steps);
}

void	draw_line(double x1, double y1, double x2, double y2, t_cube *data)
{
	int		k;
	int		steps;
	double	x;
	double	y;
	double	x_incr;
	double	y_incr;

	x_incr = calc_incr(x1, y1, x2, y2, 1);
	y_incr = calc_incr(x1, y1, x2, y2, 2);
	steps = (int)calc_incr(x1, y1, x2, y2, 3);
	x = x1;
	y = y1;
	k = 0;
	while (k < steps)
	{
		ft_pixel_put(data, x, y, data->ray_color);
		x += x_incr;
		y += y_incr;
		k++;
	}
}

void	raycast(t_cube *data, double ray_num)
{
	double	i_band;
	double	coord_y_wall_diff;
	double	ray_len;

	i_band = 0;
	while (i_band <= data->band_w)
	{
		// ray_len = sqrt((ft_abs(data->player.x2 - data->player.x1) * \
		// ft_abs(data->player.x2 - data->player.x1)) + (ft_abs(data->player.y2 \
		// - data->player.y1) * ft_abs(data->player.y2 - data->player.y1))) - 1;
		// printf("end axes = %f, len = %f\n", data->end_axes, ray_len);
		ray_len = data->end_axes * 10;
		coord_y_wall_diff = WINDOW_Y * 0.5 / ray_len * 10;
		if (coord_y_wall_diff > data->head)
			coord_y_wall_diff = data->head;
		draw_line(i_band + (ray_num - data->incr) * data->band_w, data->head + coord_y_wall_diff, \
				i_band + (ray_num - data->incr) * data->band_w, data->head - coord_y_wall_diff, data);
		i_band++;
	}
}
#include <time.h>

void	next_frame(t_cube *data)
{
	static int		frameCount = 0;
	static clock_t	startTime = 0;
	double			elapsedTime;
	if (startTime == 0)
		startTime = clock();

	double	ray_num;
	double	tmp_theta = data->player.theta - FOV * 0.5;

	ray_num = 0;
	fill_background(data);
	while (tmp_theta < (data->player.theta + ((double)FOV * 0.5)))
	{
		algo_ray_end(data, ray_num);
		raycast(data, ray_num);
		tmp_theta += data->incr;
		ray_num += data->incr;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	
	if (data->show_fps == 1)
	{
		frameCount++;
		elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
		if (elapsedTime >= 1.0)
		{
			printf("FPS: %d\n", frameCount);
			frameCount = 0;
			startTime = clock();
		}
	}
}
