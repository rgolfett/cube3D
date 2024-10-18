/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:59:10 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/18 12:24:37 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

int	deal_key(int key, t_cube *data)
{
	// printf("key == %d\n", key);

	if (key == 65307)
		mlx_loop_end(data->mlx);
	else if (key == 's')
	{
		data->player.x1 += 1 * -cos(data->player.theta /180 * MY_PI);
		data->player.y1 += 1 * -sin(data->player.theta /180 * MY_PI);
	}
	else if (key == 'w')
	{
		data->player.x1 += 1 * cos(data->player.theta /180 * MY_PI);
		data->player.y1 += 1 * sin(data->player.theta /180 * MY_PI);
	}
	else if (key == 'a')
	{
		data->player.x1 += 1 * cos((data->player.theta - 90) /180 * MY_PI);
		data->player.y1 += 1 * sin((data->player.theta - 90) /180 * MY_PI);
	}
	else if (key == 'd')
	{
		data->player.x1 += 1 * cos((data->player.theta + 90) /180 * MY_PI);
		data->player.y1 += 1 * sin((data->player.theta + 90) /180 * MY_PI);
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
	else if (key == 'f')
		data->show_fps *= -1;
	// printf("zoom = %d\n", data->arg.zoom);
	// printf("theta == %f\n", data->player.theta);
	// printf("x2 == %f\n", data->player.x2);
	// printf("y2 == %f\n", data->player.y2);
	return 0;
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
