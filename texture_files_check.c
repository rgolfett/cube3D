#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

char	*get_texture_name(char *str, char *texture)
{
	int	i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	if (text_utils(&str[i]) == 1)
		return (NULL);
	texture = malloc(sizeof (char) * (ft_strlen(&str[i]) + 1));
	if (!texture)
		return (NULL);
	ft_cpy(&str[i], texture);
	// printf("texture = -%s-\n", texture);
	return (texture);
}

int	ft_is_north(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (str[i] == ' ')
		tab[1]++;
	else if (str[i] == 'O')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[0]++;
	}
	else
		return (printf("Invalid NO\n"), 1);
	arg->NO_file = get_texture_name(&str[i], arg->NO_file);
	// printf("here str = *%s*\n", arg->NO_file);
	if (arg->NO_file == NULL)
		return (printf("Invalid NO file\n"), 1);
	return (0);
}

int	ft_is_east(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (str[i] == ' ')
		tab[2]++;
	else if (str[i] == 'A')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[1]++;
	}
	else
		return (printf("Invalid EA\n"), 1);
	arg->EA_file = get_texture_name(&str[i], arg->EA_file);
	if (arg->EA_file == NULL)
		return (printf("Invalid EA file\n"), 1);
	return (0);
}

int	ft_is_west(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (str[i] == ' ')
		tab[3]++;
	else if (str[i] == 'E')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[2]++;
	}
	else
		return (printf("Invalid WE\n"), 1);
	arg->WE_file = get_texture_name(&str[i], arg->WE_file);
	if (arg->WE_file  == NULL)
		return (printf("Invalid WE file\n"), 1);
	return (0);
}

int	ft_is_south(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (str[i] == ' ')
		tab[4]++;
	else if (str[i] == 'O')
	{
		i++;
		if (str[i] != ' ')
			return (1);
		tab[3]++;
	}
	else
		return (printf("Invalid SO\n"), 1);
	arg->SO_file = get_texture_name(&str[i], arg->SO_file);
	if (arg->SO_file  == NULL)
		return (printf("Invalid SO file\n"), 1);
	return (0);
}

