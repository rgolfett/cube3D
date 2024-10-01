#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

int	ft_check_color_validity(t_arg *arg)
{
	if (arg->ceiling.R == -1)
		return (1);
	if (arg->ceiling.G == -1)
		return (1);
	if (arg->ceiling.B == -1)
		return (1);
	if (arg->floor.R == -1)
		return (1);
	if (arg->floor.G == -1)
		return (1);
	if (arg->floor.B == -1)
		return (1);
	return (0);
}

int	ft_floor_utils(char *nb)
{
	int	color;

	color = 0;
	color = ft_atoi(nb);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}


int	ft_fill_utils(char *str)
{
	int		i;
	int		j;
	char	nb[3];

	i = 0;
	j = 0;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		if (j > 3)
			return (-1);
		nb[j] = str[i];
		i++;
		j++;
	}
	if (j < 3)
		nb[j] = '\0';
	if (j == 0)
		return (-1);
	return (ft_floor_utils(nb));
}

int	ft_fill_floor(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		arg->floor.R = ft_fill_utils(&str[i]);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		if (!str[i] || str[i] != ',')
			return (1);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		i++;
		arg->floor.G = ft_fill_utils(&str[i]);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		if (str[i])
			arg->floor.B = ft_fill_utils(&str[i]);
		else
			return (1);
		return (0);
	}
	while (str[i] && is_whitespace(str[i]) == 0)
		i++;
	if (str[i] != '\n' || str[i] != '\0')
		return (1);
	return (0);
}

int	ft_fill_ceiling(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		arg->ceiling.R = ft_fill_utils(&str[i]);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		if (!str[i] || str[i] != ',')
			return (1);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		i++;
		arg->ceiling.G = ft_fill_utils(&str[i]);
		while (str[i] && ft_isdigit(str[i]) == 0)
			i++;
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		if (str[i])
			arg->ceiling.B = ft_fill_utils(&str[i]);
		else
			return (1);
		return (0);
	}
	while (str[i] && is_whitespace(str[i]) == 0)
		i++;
	if (str[i] != '\n' || str[i] != '\0')
		return (1);
	return (0);
}

int	ft_limits_check(char *str, t_arg *arg)
{
	int	i;

	i = 0;
	if (str[0] == 'F')
	{
		i++;
		if (!str[i])
			return (printf("empty str\n"), 1);
		if (ft_fill_floor(&str[i], arg) == 1)
			return (printf("wrong floor\n"), 1);
	}
	else if (str[0] == 'C')
	{
		i++;
		if (!str[i])
			return (printf("empty str\n"), 1);
		if (ft_fill_ceiling(&str[i], arg) == 1)
			return (printf("wrong ceiling\n"), 1);
	}
	if (ft_check_color_validity(arg) == 1)
		return (printf("wrong color_validity\n"), 1);
	return (0);
}
