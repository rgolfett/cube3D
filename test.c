#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

int	on_key_press(int key, t_cube *data)
{
	printf("key = %i\n", key);
	printf("x = %i, y = %i\n", data->player.x, data->player.y);
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else if (key == KEY_A)
		data->player.x -= 10;
	else if (key == KEY_W)
		data->player.y -= 10;
	else if (key == KEY_S)
		data->player.y += 10;
	else if (key == KEY_D)
		data->player.x += 10;
	// if (key == KEY_RIGHT)
	// if (key == KEY_LEFT)
	return (0);
}

void    my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
    char    *dst;

    if ((x <= WINDOW_X && x >= 0) && (y <= WINDOW_Y && y >= 0))
    {
        dst = image->adress + (y * image->size_line + x * \
				(image->bits_per_adress / 8));
		*(unsigned int *)dst = color;
    }
}

int	ft_loop(t_cube *data)
{
	mlx_clear_window(data->mlx, data->window);
	my_mlx_pixel_put(&data->image, data->player.x, data->player.y, 0xff0000);

	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	ft_test(void)
{
	t_cube data;
	data.mlx = mlx_init();
	data.player.x = 250;
	data.player.y  = 250;
		printf("x = %i, y = %i\n", data.player.x, data.player.y);
	data.window = mlx_new_window(data.mlx, WINDOW_X, WINDOW_Y, "cube3D");
	data.image.image = mlx_new_image(data.mlx, WINDOW_X, WINDOW_Y);
	data.image.adress = mlx_get_data_addr(data.image.image, 
		&data.image.bits_per_adress, &data.image.size_line, &data.image.endian);
	mlx_hook(data.window, 17, 0, mlx_loop_end, data.mlx);
	mlx_hook(data.window, 2, 1, on_key_press, &data);
	mlx_loop_hook(data.mlx, ft_loop, &data);
	mlx_loop(data.mlx);

	return (0);
}