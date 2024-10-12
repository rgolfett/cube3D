/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:31:20 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/12 17:28:15 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	ft_check_color_validity(t_arg *arg)
{
	if (arg->ceiling.r == -1)
		return (1);
	if (arg->ceiling.g == -1)
		return (1);
	if (arg->ceiling.b == -1)
		return (1);
	if (arg->floor.r == -1)
		return (1);
	if (arg->floor.g == -1)
		return (1);
	if (arg->floor.b == -1)
		return (1);
	return (0);
}

int	ft_floor_utils(char *nb)
{
	int	color;

	color = 0;
	if (nb == NULL)
		return (-1);
	color = ft_atoi(nb);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}

int	ft_fill_utils(char *str)
{
	int		i;
	int		j;
	char	nb[4];

	i = 0;
	j = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		if (j > 3)
			return (-1);
		nb[j] = str[i];
		i++;
		j++;
	}
	nb[j] = '\0';
	if (j == 0)
		return (-1);
	return (ft_floor_utils(nb));
}

int	ft_whitespace_utils(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) == 1)
		i++;
	return (i);
}

int	ft_isdigit_utils(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]) == 0)
		i++;
	return (i);
}
