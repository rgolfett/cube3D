/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:12:53 by kiparis           #+#    #+#             */
/*   Updated: 2024/11/04 13:28:19 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

int	move_mouse(t_cube *data)
{
	int	pos_mouse_x;
	int	pos_mouse_y;
	int	lim_x;
	int	lim_y;

	pos_mouse_x = 0;
	pos_mouse_y = 0;
	lim_x = WINDOW_X / 10;
	lim_y = WINDOW_Y / 10;
	mlx_mouse_get_pos(data->mlx, data->window, &pos_mouse_x, &pos_mouse_y);
	if (pos_mouse_x > WINDOW_X - lim_x || pos_mouse_y > WINDOW_Y - lim_y || \
		pos_mouse_x < lim_x || pos_mouse_y < lim_y)
	{
		data->mouse.old_mouse_x = data->mouse.mid_x;
		data->mouse.old_mouse_y = data->mouse.mid_y;
		pos_mouse_x = data->mouse.mid_x;
		pos_mouse_y = data->mouse.mid_y;
		mlx_mouse_move(data->mlx, data->window, \
				data->mouse.mid_x, data->mouse.mid_y);
	}
	data->player.theta \
			+= (pos_mouse_x - data->mouse.old_mouse_x) * ROTATION_SPEED;
	data->mouse.old_mouse_x = pos_mouse_x;
	return (0);
}

int	move_key(int key, t_cube *data)
{
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	if (key == KEY_W)
		data->arg.m_key.press_w = 1;
	if (key == KEY_A)
		data->arg.m_key.press_a = 1;
	if (key == KEY_S)
		data->arg.m_key.press_s = 1;
	if (key == KEY_D)
		data->arg.m_key.press_d = 1;
	if (key == KEY_F)
		pause_mode(data);
	if (key == KEY_LEFT)
		data->arg.m_key.look_left = 1;
	if (key == KEY_RIGHT)
		data->arg.m_key.look_right = 1;
	if (key == KEY_SHIFT)
		data->player.sprint = 2;
	return (0);
}

int	move_key_zero(int key, t_cube *data)
{
	if (key == KEY_W)
		data->arg.m_key.press_w = 0;
	if (key == KEY_A)
		data->arg.m_key.press_a = 0;
	if (key == KEY_S)
		data->arg.m_key.press_s = 0;
	if (key == KEY_S)
		data->arg.m_key.press_d = 0;
	if (key == KEY_LEFT)
		data->arg.m_key.look_left = 0;
	if (key == KEY_RIGHT)
		data->arg.m_key.look_right = 0;
	if (key == KEY_SHIFT)
		data->player.sprint = 1;
	return (0);
}

int	deal_key(t_cube *data)
{
	if (data->arg.m_key.press_s == 1)
		if (!data->pause_mode)
			move_back(data);
	if (data->arg.m_key.press_w == 1)
		if (!data->pause_mode)
			move_front(data);
	if (data->arg.m_key.press_a == 1)
		if (!data->pause_mode)
			move_left(data);
	if (data->arg.m_key.press_d == 1)
		if (!data->pause_mode)
			move_right(data);
	if (data->arg.m_key.look_left == 1)
		if (!data->pause_mode)
			data->player.theta -= ROTATION_SPEED * 10;
	if (data->arg.m_key.look_right == 1)
		if (!data->pause_mode)
			data->player.theta += ROTATION_SPEED * 10;
	return (0);
}

int	deal_mouse(int button, int x, int y, t_cube *data)
{
	printf("mouse %d\n", button);
	if (button == 5)
		data->player.theta += 3;
	if (button == 4)
		data->player.theta -= 3;
	if (button == 1)
	{
	}
	if (button == 3)
	{
	}
	return (0);
	(void)button;
	(void)data;
	(void)y;
	(void)x;
}
