#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

int	get_texture_name(char *str, char *texture)
{
	int	i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 0)
		i++;
	if (!str[i] || str[i] != '.')
		return (1);
	i++;
	if (!str[i] || str[i] != '/')
		return (1);
	texture = malloc(sizeof (char) * (ft_strlen(&str[i]) + 1));
	if (!texture)
		return (2);
	ft_cpy(&str[i], texture);
	return (0);
}

int	ft_is_north(char *str, int tab[4], t_arg *arg)
{
	int	i;
	int	valid;

	i = 1;
	valid = 0;
	if (str[i] == ' ')
		tab[1]++;
	else if (str[i] == 'O')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[1]++;
	}
	else
		return (printf("Invalid NO\n"), 1);
	valid = get_texture_name(str, arg->NO_file);
	if (valid == 1)
		return (printf("Invalid EA file\n"));
	if (valid == 2)
		return (printf("Malloc failed\n"));
	return (0);
}

int	ft_is_east(char *str, int tab[4], t_arg *arg)
{
	int	i;
	int	valid;

	i = 1;
	valid = 0;
	if (str[i] == ' ')
		tab[2]++;
	else if (str[i] == 'A')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[2]++;
	}
	else
		return (printf("Invalid EA\n"), 1);
	valid = get_texture_name(str, arg->NO_file);
	if (valid == 1)
		return (printf("Invalid EA file\n"));
	if (valid == 2)
		return (printf("Malloc failed\n"));
	return (0);
}

int	ft_is_west(char *str, int tab[4], t_arg *arg)
{
	int	i;
	int	valid;

	i = 1;
	valid = 0;
	if (str[i] == ' ')
		tab[3]++;
	else if (str[i] == 'E')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[3]++;
	}
	else
		return (printf("Invalid WE\n"), 1);
	valid = get_texture_name(str, arg->NO_file);
	if (valid == 1)
		return (printf("Invalid WE file\n"));
	if (valid == 2)
		return (printf("Malloc failed\n"));
	return (0);
}

int	ft_is_south(char *str, int tab[4], t_arg *arg)
{
	int	i;
	int	valid;

	i = 1;
	valid = 0;
	if (str[i] == ' ')
		tab[4]++;
	else if (str[i] == 'O')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[4]++;
	}
	else
		return (printf("Invalid SO\n"), 1);
	valid = get_texture_name(str, arg->NO_file);
	if (valid == 1)
		return (printf("Invalid SO file\n"));
	if (valid == 2)
		return (printf("Malloc failed\n"));
	return (0);
}

