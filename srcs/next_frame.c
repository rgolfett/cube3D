/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:00:36 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/12 15:41:52 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

size_t	ft_line_len(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	abs(int n)
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
	if (abs((int)dx) > abs((int)dy))
		steps = abs((int)dx);
	else
		steps = abs((int)dy);
	if (option == 1)
		return (dx / steps);
	else if (option == 2)
		return (dy / steps);
	else
		return (steps);
}

void	tracersegment(double x1, double y1, double x2, double y2, t_cube *data)
{
	int		k;
	int		steps;
	double	x;
	double	y;
	double	x_incr;
	double	y_incr;

	// printf("x1 = %f, y1 = %f, x2 = %f, y2 = %f\n", x1, y1, x2, y2);
	x_incr = calc_incr(x1, y1, x2, y2, 1);
	y_incr = calc_incr(x1, y1, x2, y2, 2);
	steps = (int)calc_incr(x1, y1, x2, y2, 3);
	x = x1;
	y = y1;
	k = 0;
	while (k < steps)
	{
		// write(1, "test\n", 5);
		ft_pixel_put(data, x, y, data->ray_color);
		x += x_incr;
		y += y_incr;
		k++;
	}
}

void	fill_background(t_cube *data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= WINDOW_Y)
	{
		x = 0;
		while (x <= WINDOW_X)
		{
			my_mlx_pixel_put(&(data)->image, x, y, 0x777777);
			x++;
		}
		y++;
	}
}

void	algo_iso(t_cube *data, double d_theta)
{
	double	x;
	double	y;
	double	theta;

	x = data->player.x1;
	y = data->player.y1;
	theta = d_theta / 180.0 * M_PI;
	data->player.x2 = (double)(x + 40 * cos(theta));
	data->player.y2 = (double)(y + 40 * sin(theta));
}

void	accurate_raycasting(t_cube *data, double theta)
{
	double	diff_x;
	double	diff_y;
	int		tmp_x;
	int		tmp_y;

	// data->player.x2 *= data->arg.zoom;
	// data->player.y2 *= data->arg.zoom;
	printf("sin == %f, cos == %f, theta = %f\n", sin(theta), cos(theta), theta * 180 / M_PI);
	tmp_x = (int)data->player.x1 * -cos(theta);
	// if (cos(theta) >= 0)
		// tmp_x += cos(theta);
	tmp_y = (int)data->player.y1 * -sin(theta);
	// if (sin(theta) >= 0)
		// tmp_y += sin(theta);
	diff_x = tmp_x % data->arg.zoom;
	diff_y = tmp_y % data->arg.zoom;
	// printf("x1 = %f, y1 = %f, diff_x = %f, diff_y = %f\n", data->player.x1, data->player.y1, diff_x, diff_y);
	data->player.x2 += diff_x * cos(theta);
	data->player.y2 += diff_y * sin(theta);

}

void	algo_raycasting(t_cube *data, double d_theta)
{
	double	tmp_x;
	double	tmp_y;
	double	end_x = 1;
	double	end_y = 1;
	double	theta;

	data->player.x_pos_map = data->player.x1 / data->arg.zoom;
	data->player.y_pos_map = data->player.y1 / data->arg.zoom;
	data->player.x2 = data->player.x1;
	data->player.y2 = data->player.y1;
	theta = d_theta / 180.0 * M_PI;

	tmp_x = (double)(data->player.x_pos_map + cos(theta));
	tmp_y = (double)(data->player.y_pos_map + sin(theta));
	while (data->arg.s_map.map[(int)tmp_y][(int)tmp_x] != '1' && data->arg.s_map.map[(int)tmp_y][(int)tmp_x])
	{
		data->player.x2 = tmp_x * data->arg.zoom;
		data->player.y2 = tmp_y * data->arg.zoom;
		end_x++;
		end_y++;
		tmp_x = (double)(data->player.x_pos_map + end_x * cos(theta));
		tmp_y = (double)(data->player.y_pos_map + end_y * sin(theta));
	}
	accurate_raycasting(data, theta);
}

// void	algo_raycasting(t_cube *data, double d_theta)
// {
// 	double	end_x = 1;
// 	double	end_y = 1;
// 	double	theta;

// 	data->player.x_pos_map = data->player.x1 / data->arg.zoom;
// 	data->player.y_pos_map = data->player.y1 / data->arg.zoom;
// 	theta = d_theta / 180.0 * M_PI;

// 	data->player.x2 = (double)(data->player.x_pos_map + cos(theta));
// 	data->player.y2 = (double)(data->player.y_pos_map + sin(theta));
// 	while (data->arg.map.map[(int)data->player.y2][(int)data->player.x2] != '1' && data->arg.map.map[(int)data->player.y2][(int)data->player.x2])
// 	{
// 		end_x++;
// 		end_y++;
// 		data->player.x2 = (double)(data->player.x_pos_map + end_x * cos(theta));
// 		data->player.y2 = (double)(data->player.y_pos_map + end_y * sin(theta));
// 	}
// 	data->player.x2 *= data->arg.zoom;
// 	data->player.y2 *= data->arg.zoom;
// }

void	trace_square(size_t x, size_t y, t_cube *data, int color)
{
	size_t	zoom;
	size_t	tmp_x;
	size_t	tmp_y;

	zoom = data->arg.zoom;
	
	tmp_y = y * zoom;
	// tracersegment(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
	// tracersegment(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
	// tracersegment(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
	// tracersegment((x + 1) * zoom, y * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
	while (tmp_y <= ((y + 1) * zoom))
	{
		tmp_x = x * zoom;
		while (tmp_x <= ((x + 1) * zoom))
		{
			my_mlx_pixel_put(&data->image, tmp_x, tmp_y, color);
			tmp_x++;
		}
		tmp_y++;
	}
}

int	next_frame(t_cube *data)
{
	double tmp_theta = data->player.theta - FOV / 2;
	fill_background(data);
	
	size_t x;
	size_t y = 0;
	while (data->arg.s_map.map[y])
	{
		x = 0;
		while (data->arg.s_map.map[y][x])
		{
			if (data->arg.s_map.map[y][x] == '1')
				trace_square(x, y, data, 0x0000ff);
			x++;
		}
		y++;
	}

	data->ray_color = 0x00ff00;
	while (tmp_theta <= data->player.theta + FOV / 2)
	{
		// algo_iso(data, tmp_theta);
		algo_raycasting(data, tmp_theta);
		tracersegment(data->player.x1, data->player.y1, data->player.x2, data->player.y2, data);
		tmp_theta += 1;
		data->ray_color -= (255 / FOV << 8);
		data->ray_color += (255 / FOV << 16);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}