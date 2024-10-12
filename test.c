#include "cube_3D.h"

// int	on_key_press(int key, t_cube *data)
// {
// 	printf("key = %i\n", key);
// 	printf("x = %i, y = %i\n", data->player.x, data->player.y);
// 	if (key == KEY_ESC)
// 		mlx_loop_end(data->mlx);
// 	else if (key == KEY_A)
// 		data->player.x -= 10;
// 	else if (key == KEY_W)
// 		data->player.y -= 10;
// 	else if (key == KEY_S)
// 		data->player.y += 10;
// 	else if (key == KEY_D)
// 		data->player.x += 10;
// 	// if (key == KEY_RIGHT)
// 	// if (key == KEY_LEFT)
// 	return (0);
// }

// // void    my_mlx_pixel_put(t_image *image, int x, int y, int color)
// // {
// //     char    *dst;

// //     if ((x <= WINDOW_X && x >= 0) && (y <= WINDOW_Y && y >= 0))
// //     {
// //         dst = image->adress + (y * image->size_line + x * \
// // 				(image->bits_per_adress / 8));
// // 		*(unsigned int *)dst = color;
// //     }
// // }

// int	draw_new(t_cube *data, double radiant)
// {
// 	double new1 = 0;
// 	double new2 = 0;

// 	new1 = cos(data->player.x1) +  sin(data->player.y1);
// 	new2 = cos(data->player.x2) -  sin(data->player.y2);
// 	my_mlx_pixel_put(&data->image, (int)new1, (int)new2, 0x0fffff);
// }

// int	draw_line(t_cube *data, double radiant)
// {
// 	double diff_x;
// 	double	diff_y;
// 	double	incr_x;
// 	double	incr_y;
// 	int	steps;
// 	double	x;
// 	double y;

	
// 	diff_x = (data->player.x2 -data->player.x1); // 0, 0
// 	diff_y = (data->player.y2 -data->player.y1); // 0, 0
// 	if (abss(diff_x) >= abss(diff_y))
// 		steps = abss(diff_x);
// 	else
// 		steps = abss(diff_y);
// 	incr_x = diff_x/steps;
// 	incr_y = diff_y/steps;
// 	x = data->player.x1;
// 	y = data->player.y1;

// 	// printf("steps = %i\n", steps);
// 	// printf("x = %f\n", x);
// 	// printf("y = %f\n", y);
// 	// printf("incr_x = %f\n", incr_x);
// 	// printf("in y  = %f\n", incr_y);
// 	while (steps--)
// 	{
// 		my_mlx_pixel_put(&data->image, (int)x, (int)y, 0x000fff);
// 		x += incr_x;
// 		y += incr_y;
// 	}

// }

// int	algo(t_cube *data, int radiant)
// {
// 	double n_theta;

// 	n_theta = data->player.theta /180 * M_PI + radiant;
// 	data->player.x2 = (data->player.x1 + 100 * cos(n_theta));
// 	data->player.y2 = (data->player.y1 + 100 * sin(n_theta));
		
	
// }

// int	ft_loop(t_cube *data)
// {
// 	int	radiant = 0;
// 	int  nb_rad = 5;

// 	data->image.image = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
// 	data->image.adress = mlx_get_data_addr(data->image.image, 
// 		&data->image.bits_per_adress, &data->image.size_line, &data->image.endian);
// 		mlx_put_image_to_window(data->mlx,data->window, data->image.image, 0, 0);
// 	//mlx_clear_window(data->mlx, data->window);
// 	while (nb_rad > 0)
// 	{
// 		draw_new(data, radiant);
// 		algo(data, radiant);
// 		draw_line(data, radiant);
// 		radiant += (M_PI/6);
// 		nb_rad--;
// 	}
// 	//draw_line(data, radiant);
// 	printf("bits = %i, size = %i, endian = %i\n",data->image.bits_per_adress, data->image.size_line, data->image.endian);
// 	my_mlx_pixel_put(&data->image, data->player.x1, data->player.y1, 0xffff00);
// 	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);

// 	mlx_destroy_image(data->mlx,data->image.image);
// 	return (0);
// }

// int	ft_test(void)
// {
// 	t_cube data;
// 	data.mlx = mlx_init();
// 	data.player.x1 = 250;
// 	data.player.y1  = 250;
// 	data.player.theta = 0;
// 		printf("x = %i, y = %i\n", (int)data.player.x1, (int)data.player.y1);
// 	data.window = mlx_new_window(data.mlx, WINDOW_X, WINDOW_Y, "cube3D");
// 	//data.image.image = mlx_new_image(data.mlx, WINDOW_X, WINDOW_Y);
// 	//data.image.adress = mlx_get_data_addr(data.image.image, 
// 	//	&data.image.bits_per_adress, &data.image.size_line, &data.image.endian);
// 	mlx_hook(data.window, 17, 0, mlx_loop_end, data.mlx);
// 	mlx_hook(data.window, 2, 1, on_key_press, &data);
// 	mlx_loop_hook(data.mlx, ft_loop, &data);
// 	mlx_loop(data.mlx);

// // 	return (0);
// }