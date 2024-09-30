#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

int	file_is_valid(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}
int	is_cardinal(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (is_whitespace(str[i]) == 0)
			i++;
		if (str[i] == "N")
		{
			if (ft_is_north(&str[i],tab, arg) == 1)
				return (1);
		}
		// if (str[i] == "S")
		// if (str[i] == "E")
		// if (str[i] == "W")
	}
	return (0);
}

int	check_cardinal(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 0;
	while (is_whitespace(str[i]) == 1)
		i++;
	if (str[i])
		is_cardinal(&str[i], tab, arg);
	return (0);
}
int check_file(char *file, t_arg *arg)
{
	int	i;
	int file_fd;
	int tab[4];

	i = 1;
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (1);
	ft_memset(tab, 0, 4);
	if (ft_create_arg(file, file_fd, arg) == 1)
		return (1);
	while (arg->content[i])
	{
		if (check_cardinal(&file[i], tab, arg) == 1)
			return (1);
		i++;
	}
	return (0);
}