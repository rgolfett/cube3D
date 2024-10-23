/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_deal_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:17:05 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/23 15:53:16 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

void	move_back(t_cube *data)
{
	if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED
		* data->player.sprint * -cos(data->player.theta / 180 * MY_PI))] == '0')
		data->player.x1 += SPEED * data->player.sprint * \
		-cos(data->player.theta / 180 * MY_PI);
	if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * \
	data->player.sprint * -sin(data->player.theta / 180 * \
	MY_PI))][(int)data->player.x1] == '0')
		data->player.y1 += SPEED * data->player.sprint * \
		-sin(data->player.theta / 180 * MY_PI);
}

void	move_front(t_cube *data)
{
	if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED
		* data->player.sprint * cos(data->player.theta / 180 * MY_PI))] == '0')
		data->player.x1 += SPEED * data->player.sprint * \
		cos(data->player.theta / 180 * MY_PI);
	if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * \
	data->player.sprint * sin(data->player.theta / 180 * \
	MY_PI))][(int)data->player.x1] == '0')
		data->player.y1 += SPEED * data->player.sprint * \
		sin(data->player.theta / 180 * MY_PI);
}

void	move_left(t_cube *data)
{
	if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1
		+ SPEED * data->player.sprint * cos((data->player.theta - 90) / 180
			* MY_PI))] == '0')
		data->player.x1 += SPEED * data->player.sprint * \
		cos((data->player.theta - 90) / 180 * MY_PI);
	if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * \
	data->player.sprint * sin((data->player.theta - 90) / 180 * \
	MY_PI))][(int)data->player.x1] == '0')
		data->player.y1 += SPEED * data->player.sprint * \
		sin((data->player.theta - 90) / 180 * MY_PI);
}

void	move_right(t_cube *data)
{
	if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1
		+ SPEED * data->player.sprint * cos((data->player.theta + 90) / 180
			* MY_PI))] == '0')
		data->player.x1 += SPEED * data->player.sprint * \
		cos((data->player.theta + 90) / 180 * MY_PI);
	if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * \
	data->player.sprint * sin((data->player.theta + 90) / 180 * \
	MY_PI))][(int)data->player.x1] == '0')
		data->player.y1 += SPEED * data->player.sprint * \
		sin((data->player.theta + 90) / 180 * MY_PI);
}

void	pause_mode(t_cube *data)
{
	if (data->pause_mode)
	{
		data->old_mouse_x = data->mid_x;
		data->old_mouse_y = data->mid_y;
		data->pause_mode = 0;
		mlx_mouse_hide(data->mlx, data->window);
		mlx_mouse_move(data->mlx, data->window, data->mid_x, data->mid_y);
	}
	else
	{
		data->pause_mode = 1;
		mlx_mouse_move(data->mlx, data->window, data->mid_x, data->mid_y);
		mlx_mouse_show(data->mlx, data->window);
	}
}
