/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:34:22 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 15:17:53 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	ft_walls_utils(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'E' \
				|| map[i][j] == 'W' || map[i][j] == 'S')
	{
		if (!map[i - 1][j] || map[i - 1][j] == '\n' || map[i - 1][j] == ' ')
			return (1);
		if (!map[i + 1][j] || map[i + 1][j] == '\n' || map[i + 1][j] == ' ')
			return (1);
		if (!map[i][j + 1] || map[i][j + 1] == '\n' || map[i][j + 1] == ' ')
			return (1);
		if (!map[i][j - 1] || map[i][j - 1] == '\n' || map[i][j - 1] == ' ')
			return (1);
	}
	return (0);
}

int	ft_check_map_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i][j] == '0' && (j == 0 || i == 0))
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
