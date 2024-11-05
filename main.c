/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:40:12 by rgolfett          #+#    #+#             */
/*   Updated: 2024/11/05 11:52:43 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	free_utils(t_arg *arg)
{
	if (arg->no_file)
		free(arg->no_file);
	if (arg->ea_file)
		free(arg->ea_file);
	if (arg->we_file)
		free(arg->we_file);
	if (arg->so_file)
		free(arg->so_file);
	if (arg->content)
		free_str(arg->content);
	if (arg->s_map.map)
		free_str(arg->s_map.map);
	if (arg->s_map.map_name)
		free(arg->s_map.map_name);
}

char	*ft_move_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '\n' && is_whitespace(str[i]) == 0))
		i++;
	str[i] = '\0';
	return (str);
}

void	ft_get_files_names(t_arg *arg)
{
	arg->no_file = ft_move_str(arg->no_file);
	arg->so_file = ft_move_str(arg->so_file);
	arg->ea_file = ft_move_str(arg->ea_file);
	arg->we_file = ft_move_str(arg->we_file);
}

void	ft_set_value(t_arg *arg)
{
	arg->ceiling.r = -2;
	arg->ceiling.g = -2;
	arg->ceiling.b = -2;
	arg->floor.r = -2;
	arg->floor.g = -2;
	arg->floor.b = -2;
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	arg = (t_arg){0};
	if (WINDOW_X <= 0 || WINDOW_Y <= 0)
		return (1);
	if (argc != 2)
		return (1);
	ft_set_value(&arg);
	if (check_file(argv[1], &arg) == 1)
	{
		free_utils(&arg);
		return (1);
	}
	if (ft_check_valid_map(argv[1], &arg.s_map) == 1)
	{
		free_utils(&arg);
		return (1);
	}
	ft_get_files_names(&arg);
	replace_space(arg.s_map.map);
	ft_raycasting(arg);
	free_utils(&arg);
	return (0);
}
