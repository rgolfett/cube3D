/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_files_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:29:17 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/03 13:35:14 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

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
	return (texture);
}

int	ft_is_north(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (is_whitespace(str[i]) == 1)
		tab[0]++;
	else if (str[i] == 'O')
	{
		i++;
		if (is_whitespace(str[i]) == 0)
			return (1);
		tab[0]++;
	}
	else
		return (printf("Invalid NO\n"), 1);
	arg->no_file = get_texture_name(&str[i], arg->no_file);
	if (arg->no_file == NULL)
		return (printf("Invalid NO file\n"), 1);
	return (0);
}

int	ft_is_east(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (is_whitespace(str[i]) == 1)
		tab[1]++;
	else if (str[i] == 'A')
	{
		i++;
		if (is_whitespace(str[i]) == 0)
			return (1);
		tab[1]++;
	}
	else
		return (printf("Invalid EA\n"), 1);
	arg->ea_file = get_texture_name(&str[i], arg->ea_file);
	if (arg->ea_file == NULL)
		return (printf("Invalid EA file\n"), 1);
	return (0);
}

int	ft_is_west(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (is_whitespace(str[i]) == 1)
		tab[2]++;
	else if (str[i] == 'E')
	{
		i++;
		if (is_whitespace(str[i]) == 0)
			return (1);
		tab[2]++;
	}
	else
		return (printf("Invalid WE\n"), 1);
	arg->we_file = get_texture_name(&str[i], arg->we_file);
	if (arg->we_file == NULL)
		return (printf("Invalid WE file\n"), 1);
	return (0);
}

int	ft_is_south(char *str, int tab[6], t_arg *arg)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	if (is_whitespace(str[i]) == 1)
		tab[3]++;
	else if (str[i] == 'O')
	{
		i++;
		if (is_whitespace(str[i]) == 0)
			return (1);
		tab[3]++;
	}
	else
		return (printf("Invalid SO\n"), 1);
	arg->so_file = get_texture_name(&str[i], arg->so_file);
	if (arg->so_file == NULL)
		return (printf("Invalid SO file\n"), 1);
	return (0);
}
