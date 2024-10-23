/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:31:05 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 15:33:18 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

int	ft_fill_f_tools(char *str, int i, t_arg *arg)
{
	if (str[i])
	{
		arg->floor.b = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (str[i] && str[i] != '\n')
			return (-1);
		return (i);
	}
	return (-1);
}

int	ft_fill_c_tools(char *str, int i, t_arg *arg)
{
	if (str[i])
	{
		arg->ceiling.b = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (str[i] && str[i] != '\n')
			return (-1);
		return (i);
	}
	return (-1);
}

int	ft_fill_floor(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	i += ft_whitespace_utils(&str[i]);
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		arg->floor.r = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		i += ft_whitespace_utils(&str[i]);
		arg->floor.g = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		i += ft_whitespace_utils(&str[i]);
		i = ft_fill_f_tools(str, i, arg);
		if (i == -1)
			return (1);
	}
	return (0);
}

int	ft_fill_ceiling(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	i += ft_whitespace_utils(&str[i]);
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		arg->ceiling.r = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		i += ft_whitespace_utils(&str[i]);
		arg->ceiling.g = ft_fill_utils(&str[i]);
		i += ft_isdigit_utils(&str[i]);
		i += ft_whitespace_utils(&str[i]);
		if (!str[i] || str[i] != ',')
			return (1);
		i++;
		i += ft_whitespace_utils(&str[i]);
		i = ft_fill_c_tools(str, i, arg);
		if (i == -1)
			return (1);
	}
	return (0);
}

int	ft_limits_check(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 0;
	if (str[0] == 'F')
	{
		tab[4]++;
		i++;
		if (!str[i])
			return (printf("empty string\n"), 1);
		if (ft_fill_floor(&str[i], arg) == 1)
			return (printf("wrong floor\n"), 1);
	}
	else if (str[0] == 'C')
	{
		tab[5]++;
		i++;
		if (!str[i])
			return (printf("empty string\n"), 1);
		if (ft_fill_ceiling(&str[i], arg) == 1)
			return (printf("wrong ceiling\n"), 1);
	}
	if (ft_check_color_validity(arg) == 1)
		return (printf("wrong color validity\n"), 1);
	return (0);
}
