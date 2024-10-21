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



int	move_key(int key, t_cube *data)
{
	printf("key == %d\n", key);
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

	if (key == 65361)
		data->arg.m_key.look_left = 1;
	if (key == 65363)
		data->arg.m_key.look_right = 1;
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

	if (key == 65361)
		data->arg.m_key.look_left = 0;
	if (key == 65363)
		data->arg.m_key.look_right = 0;
}

int	deal_key(t_cube *data)
{
	if (data->arg.m_key.press_s == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * -cos(data->player.theta /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * -cos(data->player.theta /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * -sin(data->player.theta /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * -sin(data->player.theta /180 * MY_PI);
	}
	if (data->arg.m_key.press_w == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * cos(data->player.theta /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * cos(data->player.theta /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * sin(data->player.theta /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * sin(data->player.theta /180 * MY_PI);
	}
	if (data->arg.m_key.press_a == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * cos((data->player.theta - 90) /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * cos((data->player.theta - 90) /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * sin((data->player.theta - 90) /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * sin((data->player.theta - 90) /180 * MY_PI);
	}
	if (data->arg.m_key.press_d == 1)
	{
		if (data->arg.s_map.map[(int)data->player.y1][(int)(data->player.x1 + SPEED * cos((data->player.theta + 90) /180 * MY_PI))] == '0')
			data->player.x1 += SPEED * cos((data->player.theta + 90) /180 * MY_PI);
		if (data->arg.s_map.map[(int)(data->player.y1 + SPEED * sin((data->player.theta + 90) /180 * MY_PI))][(int)data->player.x1] == '0')
			data->player.y1 += SPEED * sin((data->player.theta + 90) /180 * MY_PI);
	}
	if (data->arg.m_key.look_left == 1)
		data->player.theta -= ROTATION_SPEED;
	if (data->arg.m_key.look_right == 1)
		data->player.theta += ROTATION_SPEED;
	printf("x1 == %f\n", data->player.x1);
	printf("y1 == %f\n", data->player.y1);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_cube *data)
{
	printf("mouse\n");
	return (0);
	(void)button;
	(void)data;
	(void)y;
	(void)x;
}
