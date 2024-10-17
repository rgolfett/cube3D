/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:00:36 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/17 12:39:40 by rgolfett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

// size_t	ft_line_len(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	return (i);
// }

// double	ft_abs(double n)
// {
// 	if (n < 0)
// 		return (-n);
// 	else
// 		return (n);
// }

// double	calc_incr(int x1, int y1, int x2, int y2, int option)
// {
// 	double	dx;
// 	double	dy;
// 	double	steps;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	if (ft_abs(dx) > ft_abs(dy))
// 		steps = ft_abs(dx);
// 	else
// 		steps = ft_abs(dy);
// 	if (option == 1)
// 		return (dx / steps);
// 	else if (option == 2)
// 		return (dy / steps);
// 	else
// 		return (steps);
// }

// void	tracersegment(double x1, double y1, double x2, double y2, t_cube *data)
// {
// 	int		k;
// 	int		steps;
// 	double	x;
// 	double	y;
// 	double	x_incr;
// 	double	y_incr;

// 	x_incr = calc_incr(x1, y1, x2, y2, 1);
// 	y_incr = calc_incr(x1, y1, x2, y2, 2);
// 	steps = (int)calc_incr(x1, y1, x2, y2, 3);
// 	x = x1;
// 	y = y1;
// 	k = 0;
// 	while (k < steps)
// 	{
// 		ft_pixel_put(data, x, y, data->ray_color);
// 		x += x_incr;
// 		y += y_incr;
// 		k++;
// 	}
// }

// void	fill_background(t_cube *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y <= WINDOW_Y)
// 	{
// 		x = 0;
// 		while (x <= WINDOW_X)
// 		{
// 			my_mlx_pixel_put(&(data)->image, x, y, 0x0fd126);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	algo_iso(t_cube *data, double d_theta)
// {
// 	double	x;
// 	double	y;
// 	double	theta;

// 	x = data->player.x1;
// 	y = data->player.y1;
// 	theta = d_theta / 180.0 * MY_PI;
// 	data->player.x2 = (double)(x + 40 * cos(theta));
// 	data->player.y2 = (double)(y + 40 * sin(theta));
// }

// void	minimap(t_cube *data, double d_theta)
// {
// 	double tmp_x;
// 	double tmp_y;
// 	double end_x;
// 	double end_y;
// 	double theta;

// 	data->player.x_pos_map = data->player.x1 / data->arg.zoom;
// 	data->player.y_pos_map = data->player.y1 / data->arg.zoom;
// 	theta = d_theta / 180.0 * MY_PI;
// 	end_x = 0;
// 	end_y = 0;
// 	while (1)
// 	{
// 		tmp_x = data->player.x_pos_map + end_x * cos(theta);
// 		tmp_y = data->player.y_pos_map + end_y * sin(theta);
// 		if (data->arg.s_map.map[(int)tmp_y][(int)tmp_x] == '1')
// 			break;
// 		end_x += STEP_SIZE * 100;
// 		end_y += STEP_SIZE * 100;
// 	}
// 	end_x = 0;
// 	end_y = 0;
// 	while (1)
// 	{
// 		tmp_x = data->player.x_pos_map + end_x * cos(theta);
// 		tmp_y = data->player.y_pos_map + end_y * sin(theta);
// 		if (data->arg.s_map.map[(int)tmp_y][(int)tmp_x] == '1')
// 			break;
// 		end_x += STEP_SIZE * 10;
// 		end_y += STEP_SIZE * 10;
// 	}
// 	end_x = 0;
// 	end_y = 0;
// 	while (1)
// 	{
// 		tmp_x = data->player.x_pos_map + end_x * cos(theta);
// 		tmp_y = data->player.y_pos_map + end_y * sin(theta);
// 		if (data->arg.s_map.map[(int)tmp_y][(int)tmp_x] == '1')
// 			break;
// 		end_x += STEP_SIZE;
// 		end_y += STEP_SIZE;
// 	}
// 	// end_x = 0;
// 	// end_y = 0;
// 	// while (1)
// 	// {
// 	// 	tmp_x = data->player.x_pos_map + end_x * cos(theta);
// 	// 	tmp_y = data->player.y_pos_map + end_y * sin(theta);
// 	// 	if (data->arg.map.map[(int)tmp_y][(int)tmp_x] == '1')
// 	// 		break;
// 	// 	end_x += STEP_SIZE;
// 	// 	end_y += STEP_SIZE;
// 	// }

// 	data->player.x2 = tmp_x * data->arg.zoom;
// 	data->player.y2 = tmp_y * data->arg.zoom;
// }

// void	trace_square(size_t x, size_t y, t_cube *data, int color)
// {
//     size_t zoom = data->arg.zoom;
//     size_t tmp_x = x * zoom;
//     size_t tmp_y = y * zoom;
// 	size_t current_x;

//     while (tmp_y < (y + 1) * zoom) {
//         current_x = tmp_x;
//         while (current_x < (x + 1) * zoom) {
//             my_mlx_pixel_put(&data->image, current_x, tmp_y, color);
//             current_x++;
//         }
//         tmp_y++;
//     }
// }

// void	map(t_cube *data)
// {
// 	size_t x;
// 	size_t y = 0;
// 	while (data->arg.s_map.map[y])
// 	{
// 		x = 0;
// 		while (data->arg.s_map.map[y][x])
// 		{
// 			if (data->arg.s_map.map[y][x] == '1')
// 				trace_square(x, y, data, 0x0000ff);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	cube(t_cube *data, double ray_num)
// {
// 	double	i = 0;
// 	double	p_x = data->player.x1 / data->arg.zoom;
// 	double	p_y = data->player.y1 / data->arg.zoom;
// 	double	r_x = data->player.x2 / data->arg.zoom;
// 	double	r_y = data->player.y2 / data->arg.zoom;
// 	double	coord_x_wall;
// 	double	coord_y_wall;
// 	double	coord_x_wall_end;
// 	double	coord_y_wall_end;
// 	double	width = WINDOW_X / FOV;
// 	double	mid_y = WINDOW_Y / 2;
// 	double	zoom_map = 10;
// 	double	ray_len;
// 	while (i <= width)
// 	{
// 		ray_len = sqrt((ft_abs(data->player.x2 - data->player.x1) * ft_abs(data->player.x2 - data->player.x1)) + (ft_abs(data->player.y2 - data->player.y1) * ft_abs(data->player.y2 - data->player.y1))) - 1;
// 		// if (ray_num == FOV / 2)
// 		// 	printf("len == %f\n", ray_len);
// 		coord_x_wall = i + ray_num * width;
// 		coord_x_wall_end = i + ray_num * width;
// 		// printf("head == %f\n", data->head);
// 		coord_y_wall =  data->head + (mid_y / ray_len * zoom_map);
// 		coord_y_wall_end = data->head - (mid_y / ray_len * zoom_map);
// 		tracersegment(coord_x_wall, coord_y_wall, coord_x_wall_end, coord_y_wall_end, data);
// 		i++;
// 	}
// }


// void	next_frame(t_cube *data)
// {
// 	double	ray_num = 0;
// 	double tmp_theta = data->player.theta - FOV / 2;
// 	fill_background(data);
// 	map(data);
// 	// data->ray_color = 0x00ff00;
// 	while (tmp_theta <= data->player.theta + FOV / 2)
// 	{
// 		// algo_iso(data, tmp_theta);
// 		minimap(data, tmp_theta);
// 		cube(data, ray_num);
// 		map(data);
// 		tracersegment(data->player.x1, data->player.y1, data->player.x2, data->player.y2, data);
// 		my_mlx_pixel_put(&data->image, data->player.x1, data->player.y1, 0xff00ff);
// 		tmp_theta += 0.25;
// 		ray_num += 0.25;
// 		// data->ray_color -= (1 << 8);
// 		// data->ray_color += (1 << 16);
// 	}
// 	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
// }


// NEW PART

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
	double	end_axes;
	double	theta;

	end_axes = 0;
	theta = (data->player.theta + ray_num - FOV * 0.5) * INV_180 * MY_PI;
	while (1)
	{
		*tmp_x = data->player.x_pos_map + end_axes * cos(theta);
		*tmp_y = data->player.y_pos_map + end_axes * sin(theta);
		if (!data->arg.s_map.map[(int)*tmp_y][(int)*tmp_x] || \
		data->arg.s_map.map[(int)*tmp_y][(int)*tmp_x] == '1')
			break;
		end_axes += STEP_SIZE * data->axes_mul;
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
		// if (x > 1920 || y > 1080)
		// 	printf("x = %f, y =%f\n", x, y);
		ft_pixel_put(data, x, y, data->ray_color);
		x += x_incr;
		y += y_incr;
		k++;
	}
}

void	draw_utils(double x1, double y1, double x2, double y2, t_cube *data)
{
	int		k;
	int		steps;
	double	x;
	double	y;
	double	x_incr;
	double	y_incr;
	int	i;
	i = 0;
	x_incr = calc_incr(x1, y1, x2, y2, 1);
	y_incr = calc_incr(x1, y1, x2, y2, 2);
	steps = (int)calc_incr(x1, y1, x2, y2, 3);
	x = x1;
	y = y1;
	k = 0;
	while (k < steps)
	{
		ft_pixel_put(data, (int)x, (int)y, data->arg.wall.north.ad[i]);
		x += x_incr;
		y += y_incr;
		k++;
		i++;
	}
}

void	raycast(t_cube *data, double ray_num)
{
	double	i_band;
	double	coord_y_wall_diff;
	double	ray_len;

	// printf("band_w = %f\n", data->band_w);
	i_band = 0;
	while (i_band <= data->band_w)
	{
		ray_len = sqrt((ft_abs(data->player.x2 - data->player.x1) * \
		ft_abs(data->player.x2 - data->player.x1)) + (ft_abs(data->player.y2 \
		- data->player.y1) * ft_abs(data->player.y2 - data->player.y1))) - 1;
		coord_y_wall_diff = WINDOW_Y * 0.5 / ray_len * 10;
		if (coord_y_wall_diff > data->head)
			coord_y_wall_diff = data->head;
		draw_line(i_band + (ray_num - data->incr) * data->band_w, data->head + coord_y_wall_diff, \
				i_band + (ray_num - data->incr) * data->band_w, data->head - coord_y_wall_diff, data);
		//draw_utils(i_band + (ray_num - data->incr) * data->band_w, data->head + coord_y_wall_diff, \
				i_band + (ray_num - data->incr) * data->band_w, data->head - coord_y_wall_diff, data);
		// printf("ray_num = %f\n", ray_num);
		if ((ray_num >= 89) && (i_band == data->band_w))
			printf("band_w = %f, i_band = %f, nbr = %f, ray_num = %f\n", data->band_w, i_band, i_band + ray_num * data->band_w, ray_num);
		i_band++;
	}
	// printf("i_band = %f\n", i_band);
}
#include <time.h>

// void	draw_text_wall(t_cube *data, int x, float height, float wall_off)
// {
// 	int	y_start;
// 	int	nb_y_pixel;
// 	float limit;
// 	int	text_x = 0;
// 	int	text_y = 0;

// 	data->arg.wall.north.index = 0;
// 	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
// 	nb_y_pixel = WINDOW_Y * height;
// 	while (data->arg.wall.north.index < nb_y_pixel)
// 	{
// 		limit = (float)data->arg.wall.north.index / (float)nb_y_pixel;
// 		text_x = data->arg.wall.north.width * wall_off;
// 		text_y = data->arg.wall.north.height * limit;
// 		my_mlx_pixel_put(&data->image, x, y_start,
// 			data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x]);
// 		data->arg.wall.north.index++;
// 		y_start++;
// 	}
// 	data->arg.wall.north.index = 0;
// }

void	draw_text_wall(t_cube *data, int x, float height, float wall_off)
{
	int	y_start;
	int	nb_y_pixel;
	float limit;
	int	text_x = 0;
	int	text_y = 0;

	data->arg.wall.north.index = 0;
	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
	nb_y_pixel = WINDOW_Y * height;
	while (data->arg.wall.north.index < nb_y_pixel)
	{
		limit = (float)data->arg.wall.north.index / (float)nb_y_pixel;
		text_x = data->arg.wall.north.width * wall_off;
		text_y = data->arg.wall.north.height * limit;
		my_mlx_pixel_put(&data->image, x, y_start,
			data->arg.wall.north.ad[text_y * data->arg.wall.north.width + text_x]);
		data->arg.wall.north.index++;
		y_start++;
	}
	data->arg.wall.north.index = 0;
}

void	draw_column(t_cube *data, int x, float height, int side, float wall_off)
{
	int	 i;
	int	y_start;
	int	nb_y_pixel;
	int	blue;
	int	red;
	float limit;

	i = 0;
	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
	nb_y_pixel = WINDOW_Y * height;
	blue = 255;
	red = 255 << 16;
	
	while ((i + y_start) < (y_start + nb_y_pixel))
	{
		limit = (float)i / (float)nb_y_pixel;
	//	printf("limit = %f\n", limit);
			//my_mlx_pixel_put(&data->image, x, y_start, ((int)(red * limit) & 0xff0000) + blue * wall_off);
		//data->arg.wall.north.ad[i]
		i++;
		y_start++;
	}
}

void 	tmp_raycast(t_cube *data)
{
	fill_background(data);
	
	enum {
		EAST,
		SOUTH,
		WEST,
		NORTH,
	}	side_e;

	struct {
		float height;
		int side;
		float wall_off;
	}	rays[WINDOW_X];

	int i = 0;
	for (; i < WINDOW_X / 2; i++)
	{
		rays[i].height = 1.0f - ((float)i / (float)WINDOW_X);
		rays[i].side = EAST;
		rays[i].wall_off = (float)i / (float)WINDOW_X * 2;
	}
	for (; i < WINDOW_X; i++)
	{
		rays[i].height = (float)i / (float)WINDOW_X;
		rays[i].side = SOUTH;
		rays[i].wall_off = ((float)i / (float)WINDOW_X - 0.5f) * 2;
	}
	
	for (int x = 0; x < sizeof(rays) / sizeof(*rays); x++)
		draw_text_wall(data, x, rays[x].height, rays[x].wall_off);
		//draw_text_wall(&data->arg.wall.north, x, rays[x].height, rays[x].wall_off);
}

void	next_frame(t_cube *data)
{
	// static int		frameCount = 0;
	// static clock_t	startTime = 0;
	// double			elapsedTime;
	// if (startTime == 0)
	// 	startTime = clock();


	double	ray_num;
	double	tmp_theta = data->player.theta - FOV * 0.5;

	ray_num = 0;
	printf("incr = %f\n", data->incr);
	fill_background(data);
	while (tmp_theta < (data->player.theta + ((double)FOV * 0.5)))
	{
		algo_ray_end(data, ray_num);
		raycast(data, ray_num);
		tmp_theta += data->incr;
		ray_num += data->incr;
	}
	// printf("ray num = %f\n", ray_num);

	tmp_raycast(data);
	
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	
	// frameCount++;
	// elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    // if (elapsedTime >= 1.0)
	// {
	// 	printf("FPS: %d\n", frameCount);
	// 	frameCount = 0;
	// 	startTime = clock();
    // }
}
