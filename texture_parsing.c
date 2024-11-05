/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:28:05 by rgolfett          #+#    #+#             */
/*   Updated: 2024/11/05 12:02:33 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	file_parsing(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 0;
	if (str[i] == 'N')
	{
		if (ft_is_north(str, tab, arg) != 0)
			return (1);
	}
	else if (str[i] == 'E')
	{
		if (ft_is_east(str, tab, arg) != 0)
			return (1);
	}
	else if (str[i] == 'W')
	{
		if (ft_is_west(str, tab, arg) != 0)
			return (1);
	}
	else if (str[i] == 'S')
	{
		if (ft_is_south(str, tab, arg) != 0)
			return (1);
	}
	return (0);
}

int	is_cardinal(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	if (!str[i])
		return (0);
	if (str[i] == 'N' || str[i] == 'E' || str[i] == 'W' || str[i] == 'S')
	{
		if (file_parsing(&str[i], tab, arg) == 1)
			return (1);
		return (0);
	}
	else if (str[i] == 'F' || str[i] == 'C')
	{
		if (ft_limits_check(&str[i], tab, arg) == 1)
			return (1);
		return (0);
	}
	else
		return (printf("invalid file\n"), 1);
	return (0);
}

int	check_cardinal(char *str, int tab[6], t_arg *arg)
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

int	check_arg(int tab[6], t_arg *arg)
{
	int	i;

	i = 0;
	(void)arg;
	while (i <= 5)
	{
		if (tab[i] != 1)
			return (1);
		i++;
	}
	if (arg->ceiling.r == -2 || arg->ceiling.g == -2 || arg->ceiling.b == -2)
		return (1);
	if (arg->floor.r == -2 || arg->floor.g == -2 || arg->floor.b == -2)
		return (1);
	return (0);
}

int	check_file(char *file, t_arg *arg)
{
	int	i;
	int	file_fd;
	int	tab[6];

	i = 0;
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (printf("wrong fd\n"), 1);
	ft_memset(tab, 0, 6);
	if (ft_create_arg(file, file_fd, arg) == 1)
		return (printf("wrong arg\n"), 1);
	while (arg->content[i])
	{
		if (check_cardinal(arg->content[i], tab, arg) == 1)
			return (1);
		if (check_arg(tab, arg) == 0)
		{
			arg->s_map.index = (i + 1);
			return (0);
		}
		i++;
	}
	return (0);
}
