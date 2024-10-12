/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:32:37 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/12 16:43:25 by rgolfett         ###   ########lyon.fr   */
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
			if (data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x] == 'N')
				return (270);
			if (data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x] == 'S')
				return (90);
			if (data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x] == 'E')
				return (0);
			if (data->arg.s_map.map[data->player.spawn_y][data->player.spawn_x] == 'W')
				return (180);
			data->player.spawn_x++;
		}
		data->player.spawn_y++;
	}
	return (-1);
}

void	init_data(t_cube *data, t_arg arg)
{
	// data->player.theta = arg.map.direction;
	data->arg = arg;
	data->arg.zoom = 10;
	data->head = WINDOW_Y / 2;
	data->player.theta = find_spawn_point(data);
	data->player.x1 = data->player.spawn_x * data->arg.zoom + data->arg.zoom / 2;
	data->player.y1 = data->player.spawn_y * data->arg.zoom + data->arg.zoom / 2;
	data->image.image = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	data->image.adress = mlx_get_data_addr(data->image.image, \
		&data->image.bits_per_adress, &data->image.size_line, &data->image.endian);
}

void	ft_raycasting(t_arg arg)
{
	t_cube	data;
	int	pos_mouse_x;
	int pos_mouse_y;

	data.mlx = mlx_init();
	init_data(&data, arg);
	data.window = mlx_new_window(data.mlx, WINDOW_X, \
								WINDOW_Y, "Ma Fenetre");
	mlx_mouse_hide(data.mlx, data.window);
	mlx_hook(data.window, 2, 1, deal_key, &data);
	// mlx_mouse_get_pos(data.mlx, data.window, &pos_mouse_x, &pos_mouse_y);
	//printf("x = %d, y = %d\n", pos_mouse_x, pos_mouse_y);
	// mlx_mouse_hook(data.mlx, deal_mouse, &data);
	mlx_hook(data.window, 17, 0, mlx_loop_end, data.mlx);
	mlx_loop_hook(data.mlx, next_frame, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.image.image);
	mlx_mouse_show(data.mlx, data.window);
}