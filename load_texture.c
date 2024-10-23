/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:50:58 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:48 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

t_image	load_img(void *mlx, t_image *wall, char *texture)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	if (!wall)
		printf("wall == NULL\n");
	wall->image = mlx_xpm_file_to_image(mlx, texture, &wall->width, \
		&wall->height);
	printf("%d %d %p\n", wall->width, wall->height, wall->ad);
	if (wall->image)
	{
		wall->ad = (int *) \
			mlx_get_data_addr(wall->image, \
				&bits_per_pixel, &size_line, &endian);
	}
	if (!wall->image)
		printf("wall->image == NULL\n");
	return (*wall);
}

int	ft_load_sprites(t_cube *cube, t_wall *wall)
{
	wall->north = load_img(cube->mlx, &wall->north, cube->arg.no_file);
	if (!wall->north.image)
		return (1);
	wall->south = load_img(cube->mlx, &wall->south, cube->arg.so_file);
	if (!wall->south.image)
		return (1);
	wall->east = load_img(cube->mlx, &wall->east, cube->arg.ea_file);
	if (!wall->east.image)
		return (1);
	wall->west = load_img(cube->mlx, &wall->west, cube->arg.we_file);
	if (!wall->west.image)
		return (1);
	return (0);
}

void	draw_wall_utils(t_cube *data, t_image *wall, double limit, int y_start)
{
	int	text_x;
	int	text_y;

	text_x = wall->width * data->player.wall_off;
	text_y = wall->height * limit;
	((unsigned int*)(data->image.address)) \
		[y_start * data->image.width + data->x] \
			= wall->ad[text_y * wall->width + text_x];
}

void	ft_secure_height(double *i, double *height, int *nb_y_pixel)
{
	if (*height > 1.0f)
	{
		*i = (*height - 1.0f) * 100 * 4;
		*height = 1.0f;
		*nb_y_pixel = (double)WINDOW_Y * *height + *i * 2;
	}
}

void	draw_text_wall(t_cube *data, double height, int side)
{
	double	i;
	int		y_start;
	int		nb_y_pixel;
	double	limit;

	i = 0;
	nb_y_pixel = (double)WINDOW_Y * height;
	ft_secure_height(&i, &height, &nb_y_pixel);
	y_start = (WINDOW_Y / 2) - (WINDOW_Y * height / 2);
	while (i < nb_y_pixel && y_start <= WINDOW_Y)
	{
		limit = (double)i / (double)nb_y_pixel;
		if (side == 1)
			draw_wall_utils(data, &data->arg.wall.north, limit, y_start);
		else if (side == 2)
			draw_wall_utils(data, &data->arg.wall.south, limit, y_start);
		else if (side == 3)
			draw_wall_utils(data, &data->arg.wall.east, limit, y_start);
		else if (side == 4)
			draw_wall_utils(data, &data->arg.wall.west, limit, y_start);
		i++;
		y_start++;
	}
}
