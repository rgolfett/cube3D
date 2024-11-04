/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:32:37 by kiparis           #+#    #+#             */
/*   Updated: 2024/11/04 13:21:54 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

double	find_spawn_point(t_cube *data)
{
	data->player.spawn_y = 0;
	while (data->arg.s_map.map[data->player.spawn_y])
	{
		data->player.spawn_x = 0;
		while (data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x])
		{
			if (data->arg.s_map.map[data->player.spawn_y]
				[data->player.spawn_x] == 'N')
				return (180);
			if (data->arg.s_map.map[data->player.spawn_y]
				[data->player.spawn_x] == 'S')
				return (0);
			if (data->arg.s_map.map[data->player.spawn_y]
				[data->player.spawn_x] == 'E')
				return (270);
			if (data->arg.s_map.map[data->player.spawn_y]
				[data->player.spawn_x] == 'W')
				return (90);
			data->player.spawn_x++;
		}
		data->player.spawn_y++;
	}
	return (-1);
}

void	init_movements(t_cube *data)
{
	data->arg.m_key.press_w = 0;
	data->arg.m_key.press_a = 0;
	data->arg.m_key.press_s = 0;
	data->arg.m_key.press_d = 0;
	data->arg.m_key.look_left = 0;
	data->arg.m_key.look_right = 0;
	data->mouse.old_mouse_x = 0;
	data->mouse.old_mouse_y = 0;
	data->player.sprint = 1;
	data->pause_mode = 0;
}

void	init_data(t_cube *data, t_arg arg)
{
	data->arg = arg;
	data->arg.ceiling.color = (data->arg.ceiling.r << 16) | \
							(data->arg.ceiling.g << 8) | \
							data->arg.ceiling.b;
	data->arg.floor.color = (data->arg.floor.r << 16) | \
							(data->arg.floor.g << 8) | \
							data->arg.floor.b;
	data->player.theta = find_spawn_point(data);
	data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x] = '0';
	data->player.x1 = data->player.spawn_x + 0.5;
	data->player.y1 = data->player.spawn_y + 0.5;
	data->image.image = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	data->image.width = WINDOW_X;
	data->image.height = WINDOW_Y;
	data->mouse.mid_x = WINDOW_X / 2;
	data->mouse.mid_y = WINDOW_Y / 2;
	data->image.address = mlx_get_data_addr(data->image.image, &data-> \
		image.bits_per_address, &data->image.size_line, &data->image.endian);
	data->image.ad = (void *)data->image.address;
	init_movements(data);
}

void	ft_free_img(t_cube *data)
{
	if (data->arg.wall.east.image)
		mlx_destroy_image(data->mlx, data->arg.wall.east.image);
	if (data->arg.wall.south.image)
		mlx_destroy_image(data->mlx, data->arg.wall.south.image);
	if (data->arg.wall.north.image)
		mlx_destroy_image(data->mlx, data->arg.wall.north.image);
	if (data->arg.wall.west.image)
		mlx_destroy_image(data->mlx, data->arg.wall.west.image);
	if (data->image.image)
		mlx_destroy_image(data->mlx, data->image.image);
	if (data->arg.wall.pause.image)
		mlx_destroy_image(data->mlx, data->arg.wall.pause.image);
}

void	ft_raycasting(t_arg arg)
{
	t_cube	data;

	data.mlx = mlx_init();
	init_data(&data, arg);
	if (ft_load_sprites(&data, &data.arg.wall) == 1)
	{
		ft_free_img(&data);
		free(data.mlx);
		return ;
	}
	data.window = mlx_new_window(data.mlx, WINDOW_X, \
								WINDOW_Y, "cub3D");
	mlx_mouse_hide(data.mlx, data.window);
	mlx_mouse_move(data.mlx, data.window, \
			data.mouse.mid_x, data.mouse.mid_y);
	mlx_hook(data.window, 2, (1L << 0), &move_key, &data);
	mlx_hook(data.window, 3, (1L << 1), &move_key_zero, &data);
	mlx_hook(data.window, 17, 0, mlx_loop_end, data.mlx);
	mlx_loop_hook(data.mlx, &ft_display, &data);
	mlx_loop(data.mlx);
	ft_free_img(&data);
	mlx_mouse_show(data.mlx, data.window);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
