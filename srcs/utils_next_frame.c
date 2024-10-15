/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:55:21 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/15 11:57:33 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if ((x <= WINDOW_X && x >= 0) && (y <= WINDOW_Y && y >= 0))
	{
		dst = image->address + (y * image->size_line + x * \
							(image->bits_per_address / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_pixel_put(t_cube *data, int x, int y, int color)
{
	int	x_pixel;
	int	y_pixel;

	x_pixel = x;
	y_pixel = y;
	my_mlx_pixel_put(&(data)->image, x_pixel, y_pixel, color);
}
