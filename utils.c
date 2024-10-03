/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:51:17 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/03 11:51:28 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	ft_is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'W' && c != 'S' && c != 'E'&& c != 'N'\
			&& c != ' ' && c != '\n')
		return (1);
	return (0);
}

int	ft_nmb_player(char c, int cmp)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		cmp += 1;
	return (cmp);
}

int	ft_cpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2 == NULL)
		return (1);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_memset(int *tab, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		tab[i] = c;
		i++;
	}
}
