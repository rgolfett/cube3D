		/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:59:10 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/18 12:24:37 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

int	move_mouse(t_cube *data)
{
	int	pos_mouse_x = 0;
	int pos_mouse_y = 0;
	int	lim_x_screen = WINDOW_X / 10;
	int	lim_y_screen = WINDOW_Y / 10;

	mlx_mouse_get_pos(data->mlx, data->window, &pos_mouse_x, &pos_mouse_y);
	if (pos_mouse_x > WINDOW_X - lim_x_screen || pos_mouse_y > WINDOW_Y - lim_y_screen || pos_mouse_x < lim_x_screen || pos_mouse_y < lim_y_screen)
	{
		data->old_mouse_x = data->mid_x;
		data->old_mouse_y = data->mid_y;
		pos_mouse_x = data->mid_x;
		pos_mouse_y = data->mid_y;
		mlx_mouse_move(data->mlx, data->window, data->mid_x, data->mid_y);
	}	
	data->player.theta += (pos_mouse_x - data->old_mouse_x) * ROTATION_SPEED;
	data->old_mouse_x = pos_mouse_x;
	return (0);
}

int	move_key(int key, t_cube *data)
{
	// printf("key == %d\n", key);
	if (key == 65307)
		mlx_loop_end(data->mlx);
	if (key == 'w')
		data->arg.m_key.press_w = 1;
	
	if (key == 'a')
		data->arg.m_key.press_a = 1;
	
	if (key == 's')
		data->arg.m_key.press_s = 1;
	
	if (key == 'd')
		data->arg.m_key.press_d = 1;

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
	if (key == 'w')
		data->arg.m_key.press_w = 0;
	if (key == 'a')
		data->arg.m_key.press_a = 0;
	if (key == 's')
		data->arg.m_key.press_s = 0;
	if (key == 'd')
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
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * data->player.sprint  * -cos(data->player.theta /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * data->player.sprint * -cos(data->player.theta /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * data->player.sprint  * -sin(data->player.theta /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * data->player.sprint * -sin(data->player.theta /180 * MY_PI);
	}
	if (data->arg.m_key.press_w == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * data->player.sprint  * cos(data->player.theta /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * data->player.sprint * cos(data->player.theta /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * data->player.sprint  * sin(data->player.theta /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * data->player.sprint * sin(data->player.theta /180 * MY_PI);
	}
	if (data->arg.m_key.press_a == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * data->player.sprint  * cos((data->player.theta - 90) /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * data->player.sprint * cos((data->player.theta - 90) /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * data->player.sprint  * sin((data->player.theta - 90) /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * data->player.sprint * sin((data->player.theta - 90) /180 * MY_PI);
	}
	if (data->arg.m_key.press_d == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * data->player.sprint  * cos((data->player.theta + 90) /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * data->player.sprint * cos((data->player.theta + 90) /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * data->player.sprint  * sin((data->player.theta + 90) /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * data->player.sprint * sin((data->player.theta + 90) /180 * MY_PI);
	}
	if (data->arg.m_key.look_left == 1)
		data->player.theta -= ROTATION_SPEED;
	if (data->arg.m_key.look_right == 1)
		data->player.theta += ROTATION_SPEED;
	// printf("x1 == %f\n", data->player.x1);
	// printf("y1 == %f\n", data->player.y1);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_cube *data)
{
	printf("mouse %d\n", button);
	if (button == 5)
		data->player.theta += 3;
	if (button == 4 )
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