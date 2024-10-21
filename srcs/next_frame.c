/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:00:36 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/21 10:28:18 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

void	calc_end_axes(t_cube *data, double *tmp_x, double *tmp_y, double ray_num)
{
	double	theta;

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

	data->player.x_pos_map = data->player.x1 / data->arg.zoom;
	data->player.y_pos_map = data->player.y1 / data->arg.zoom;
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

double	calc_incr(double x1, double y1, double x2, double y2, int option)
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

int	find_pixel_color(t_cube *data, double height, double width, double theta)
{
	float color;
	color = floor((double)data->arg.wall.north.width * width) + floor((double)data->arg.wall.north.height * height);
	// if ((height < 0.2 || height > 0.8) && (width < 0.2 || width > 0.8))
	// 	printf("test\n");
	// printf("color = %f\n", color);
	// printf("HEIGHT = %f, width = %f\n", height, width);
	(void)theta;
	return (data->arg.wall.north.ad[(int)color]);
	
}

void raycast(t_cube *data, double ray_num, double theta)
{
	double i_band;
	// double coord_y_wall_diff;
	double ray_len;
	double wall_pos_x;
	double wall_pos_y;
	double normalized_width;
	double normalized_height;
	double apparent_wall_height;
	double wall_start_x, wall_end_x;
	double wall_start_y, wall_end_y;
	double wall_width;

	i_band = 0;
	while (i_band <= data->band_w)
	{
		ray_len = data->end_axes * 1;

		wall_pos_x = data->player.x2;
		wall_pos_y = data->player.y2;

		
		wall_start_x = floor(wall_pos_x);
		wall_end_x = ceil(wall_pos_x);
		wall_width = wall_end_x - wall_start_x;
		wall_start_y = floor(wall_pos_y);
		wall_end_y = ceil(wall_pos_y);
		wall_width = wall_end_y - wall_start_y;

		apparent_wall_height = WINDOW_Y / ray_len;
	
		normalized_width = (wall_pos_x - wall_start_x) / (wall_end_x - wall_start_x);
		// normalized_height = (wall_pos_y - wall_start_y) / apparent_wall_height;
		// normalized_width = fmax(0, fmin(1, normalized_width));
		// normalized_height = fmax(0, fmin(1, normalized_height));

		int	i = 0;
		double	top_wall = data->head - (apparent_wall_height / 2);
		double	bot_wall = data->head + (apparent_wall_height / 2);
		while (i < top_wall)
		{
		//	ft_pixel_put(data, i_band + (ray_num - data->incr) * data->band_w, i, data->arg.ceiling.color);
			i++;
		}
		int c = 0;
		
		while (i < bot_wall)
		{
			normalized_height = c / apparent_wall_height;
			// int color = (int)(normalized_width * 255);
			// int n_color = (int)(normalized_height * 255);
			// int final_color = (color << 16) | (color << 8) | n_color;
			ft_pixel_put(data, i_band + (ray_num - data->incr) * data->band_w, i, find_pixel_color(data, normalized_height, normalized_width, theta));
			// draw_text_wall(data, ray_num, normalized_height, 0, normalized_width);
			//my_mlx_pixel_put(&data->image, x, y_start, data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x]);
			i++;
			c++;
		}
		while (i < WINDOW_Y)
		{
		//	ft_pixel_put(data, i_band + (ray_num - data->incr) * data->band_w, i, data->arg.floor.color);
			i++;
		}
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
		raycast(data, ray_num, tmp_theta);
		tmp_theta += data->incr;
		ray_num += data->incr;
	}
	// printf("ray num = %f\n", ray_num);

	//tmp_raycast(data);
	
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
