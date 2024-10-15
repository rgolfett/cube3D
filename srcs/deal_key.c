/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:59:10 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/14 12:05:09 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

int	deal_key(int key, t_cube *data)
{
	t_player cpy;

	cpy = data->player;
	printf("key == %d\n", key);

	if (key == 65307)
		mlx_loop_end(data->mlx);
	else if (key == 's')
	{
		data->player.x1 += 5 * -cos(data->player.theta /180 * M_PI);
		data->player.y1 += 5 * -sin(data->player.theta /180 * M_PI);
	}
	else if (key == 'w')
	{
		data->player.x1 += 5 * cos(data->player.theta /180 * M_PI);
		data->player.y1 += 5 * sin(data->player.theta /180 * M_PI);
	}
	else if (key == 'a')
	{
		data->player.x1 += 5 * cos((data->player.theta - 90) /180 * M_PI);
		data->player.y1 += 5 * sin((data->player.theta - 90) /180 * M_PI);
	}
	else if (key == 'd')
	{
		data->player.x1 += 5 * cos((data->player.theta + 90) /180 * M_PI);
		data->player.y1 += 5 * sin((data->player.theta + 90) /180 * M_PI);
	}
	else if (key == 65361)
		data->player.theta -= 3;
	else if (key == 65363)
		data->player.theta += 3;
	else if (key == 65431)
		data->arg.zoom += 1;
	else if (key == 65433)
	{
		if (data->arg.zoom > 1)
			data->arg.zoom -= 1;
	}
	else if (key == 65364)
		data->head -= 5;
	else if (key == 65362)
		data->head += 5;
	if (data->arg.s_map.map[(int)data->player.y1 / 10][(int)data->player.x1 / 10] == '1')
		data->player = cpy;
	// printf("zoom = %d\n", data->arg.zoom);
	// printf("theta == %f\n", data->player.theta);ttt
	printf("x1 == %f\n", data->player.x1);
	printf("y1 == %f\n", data->player.y1);
	return 0;
}

int	deal_mouse(int button, int x, int y, t_cube *data)
{
	printf("mouse\n");
	return (0);
}
