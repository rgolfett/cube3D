/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:40:12 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/14 13:52:51 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3D.h"

void	ft_print_all(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg->content[i])
	{
		printf("content[%i] = %s\n", i, arg->content[i]);
		i++;
	}
	printf("\n\n");
	printf("n = %s\n", arg->no_file);
	printf("e = %s\n", arg->ea_file);
	printf("w = %s\n", arg->we_file);
	printf("s = %s\n", arg->so_file);
	printf("index = %i\n", arg->s_map.index);
	printf("arg->floor-> R = %i\n", arg->floor.r);
	printf("arg->floor-> G = %i\n", arg->floor.g);
	printf("arg->floor-> B = %i\n", arg->floor.b);
	printf("arg->ceiling-> R = %i\n", arg->ceiling.r);
	printf("arg->ceiling-> G = %i\n", arg->ceiling.g);
	printf("arg->ceiling-> B = %i\n", arg->ceiling.b);
	printf("\n\n");
}

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
	ft_set_value(&arg);
	// arg.ceiling = (t_color){-2};
	// arg.floor = (t_color){-2};
	if (argc != 2)
		return (1);
	if (check_file(argv[1], &arg) == 1)
		return (1);
	// int i = 0;
	// while (arg.content[i])
	// {
	// 	printf("content[%i] = %s\n", i, arg.content[i]);
	// 	i++;
	// }
	if (ft_check_valid_map(argv[1], &arg.s_map) == 1)
		return (1);
	ft_print_all(&arg);
	//ft_test();
	ft_raycasting(arg);
	free_utils(&arg);
}
	// ft_test();
