/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiparis <kiparis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:40:12 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 13:54:19 by kiparis          ###   ########.fr       */
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
	printf("|n = %s|\n", arg->no_file);
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

char	*ft_move_str(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof (char) * ft_strlen(str));
	if (tmp == NULL)
		return (NULL);
	while (str[i + 2] && str[i + 2] != '\n' && is_whitespace(str[i + 2]) == 0)
	{
		tmp[i] = str[i + 2];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

int	ft_get_files_names(t_arg *arg)
{
	arg->no_file = ft_move_str(arg->no_file);
	if (!arg->no_file)
		return (1);
	arg->so_file = ft_move_str(arg->so_file);
	if (!arg->so_file)
		return (1);
	arg->ea_file = ft_move_str(arg->ea_file);
	if (!arg->ea_file)
		return (1);
	arg->we_file = ft_move_str(arg->we_file);
	if (!arg->we_file)
		return (1);
	return (0);
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
	if (argc != 2)
		return (1);
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
	if (ft_get_files_names(&arg) == 0)
		ft_raycasting(arg);
	// ft_print_all(&arg);
	free_utils(&arg);
	return (0);
}
