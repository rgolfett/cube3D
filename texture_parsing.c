#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"


int	file_parsing(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 0;
	if (str[i] == 'N')
	{
		if (ft_is_north(str,tab, arg) != 0)
			return (1);
	}
	else if (str[i] == 'E')
	{
		if (ft_is_east(str,tab, arg) != 0)
			return (1);
	}
	else if (str[i] == 'W')
	{
		if (ft_is_west(str,tab, arg) != 0)
		return (1);
	}
	else if (str[i] == 'S')
	{
		if (ft_is_south(str,tab, arg) != 0)
			return (1);
	}
	return (0);
}

int	is_cardinal(char *str, int tab[4], t_arg *arg)
{
	int	i;

	i = 0;
	//while (str[i])
	//{
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	if (!str[i])
		return (0);
	if (str[i] == 'N' || str[i] == 'E' || str[i] == 'W' || str[i] == 'S')
	{
		if (file_parsing(&str[i], tab, arg) == 1)
			return (printf("wrong file_parsing\n"), 1);
		return (0);
	}
	else if 
		(str[i] == 'F' || str[i] == 'C')
		{
			if (ft_limits_check(&str[i], arg) == 1);
				return (printf("wrong limits_check\n"), 1);
			return (0);
		}
		// floor + C

	//}
	else
	{
	printf("c = -%c-\n", str[i]);
		return (printf("invalid file\n"),1);
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
	{
		if (is_cardinal(&str[i], tab, arg) == 1)
			return (1);
	}
	return (0);
}

int	check_arg(int tab[4], t_arg *arg)
{
	int	i;

	i = 0;
	(void)arg;
	while (i <= 3)
	{
		printf("test tab[%i] = %i\n", i, tab[i]);
		if (tab[i] != 1)
			return (1);
		i++;
	}
	if (arg->ceiling.R == -2 || arg->ceiling.G == -2 || arg->ceiling.B == -2)
		return (1);
	if (arg->floor.R == -2 || arg->floor.G == -2 || arg->floor.B == -2)
		return (1);
	// == NULL || arg->Roof == NULL)
	// return (1);
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
		return (printf("wrong fd\n"), 1);
	ft_memset(tab, 0, 4);
	if (ft_create_arg(file, file_fd, arg) == 1)
		return (printf("wrong arg\n"), 1);
	while (arg->content[i])
	{
		if (check_cardinal(arg->content[i], tab, arg) == 1)
			return (printf("wrong cardinal\n"), 1);
		if (check_arg(tab, arg) == 0)
			{
				arg->s_map.index = i;
				return (0);
			}
		i++;
	}
	return (0);
}
