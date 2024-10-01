/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:55:21 by kiparis           #+#    #+#             */
/*   Updated: 2024/10/01 12:41:02 by kiparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3D.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if ((x <= WINDOW_X && x >= 0) && (y <= WINDOW_Y && y >= 0))
	{
		dst = image->adress + (y * image->size_line + x * \
							(image->bits_per_adress / 8));
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
