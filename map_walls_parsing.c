/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:34:22 by rgolfett          #+#    #+#             */
/*   Updated: 2024/11/05 13:30:06 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	ft_walls_utils(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'E' \
				|| map[i][j] == 'W' || map[i][j] == 'S')
	{
		if (!map[i] || ft_strlen(map[i - 1]) < j)
			return (1);
		if (!map[i - 1] || !map[i - 1][j] || map[i - 1][j] == '\n')
			return (1);
		if (!map[i] || ft_strlen(map[i + 1]) < j)
			return (1);
		if (!map[i + 1] || !map[i + 1][j] || map[i + 1][j] == '\n')
			return (1);
		if (!map[i] ||!map[i][j + 1] || map[i][j + 1] == '\n')
			return (1);
		if (!map[i] || !map[i][j - 1] || map[i][j - 1] == '\n')
			return (1);
	}
	return (0);
}

int	ft_check_first_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] && map[i][j] == '\n')
		i++;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1' && map[i][j] != 32)
			return (1);
		j++;
	}
	return (0);
}

int	ft_is_not_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	ft_check_map_walls(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_check_first_line(map) == 1)
		return (1);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				if (ft_is_not_wall(map[i][j]) == 1 && (j == 0 || i == 0))
					return (printf("wrong walls, out of bounds\n"), 1);
				if (ft_walls_utils(map, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
