/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:30:31 by rgolfett          #+#    #+#             */
/*   Updated: 2024/11/04 18:30:37 by rgolfett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

int	file_is_valid(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

int	text_utils(char *str)
{
	// int	i;

	// i = 0;
	// while (str[i])
	// {
	// 	if (!str[i] || str[i] != '.')
	// 		return (1);
	// 	i++;
	// 	if (!str[i] || str[i] != '/')
	// 		return (1);
	// 	return (0);
	// }
	return (0);
}
