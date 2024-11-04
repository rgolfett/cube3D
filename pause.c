/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:52:23 by rgolfett          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:09 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	pause_utils(t_cube *data, float ratio_x, float ratio_y, int i)
{
	int	x;
	int	y;

	x = (int)(i % WINDOW_X * ratio_x);
	y = (int)(i / WINDOW_X * ratio_y);
	if (x < data->arg.wall.pause.width && y < data->arg.wall.pause.height)
		data->image.ad[i] \
			= data->arg.wall.pause.ad[y * data->arg.wall.pause.width + x];
	else
		data->image.ad[i] = PAUSE_COLOR;
}

void	pause_screen(t_cube *data)
{
	int		i;
	int		nb_pixel;
	float	ratio_x;
	float	ratio_y;

	i = 0;
	nb_pixel = WINDOW_X * WINDOW_Y;
	if (data->arg.wall.pause.image == NULL)
	{
		while (i < nb_pixel)
		{
			data->image.ad[i] = PAUSE_COLOR;
			i++;
		}
		return ;
	}
	ratio_y = (float)data->arg.wall.pause.height / WINDOW_Y;
	ratio_x = (float)data->arg.wall.pause.width / WINDOW_X;
	while (i < nb_pixel)
	{
		pause_utils(data, ratio_x, ratio_y, i);
		i++;
	}
}
