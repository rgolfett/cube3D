#include "cube_3D.h"
#include "get_next_line.h"

int	ft_check_map_composure(char **map)
{
	int	i;
	int	j;
	int player;

	i = 0;
	j = 0;
	player = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (ft_is_valid(map[i][j]) == 1)
				return (1);
			player = ft_nmb_player(map[i][j], player);
			j++;
		}
		i++;
		j = 0;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	ft_fill_map(char *map_name, int map_fd, t_map *s_map)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = "0";
	s_map->index = 1;
	map_fd = open(map_name, O_RDONLY);
	while (tmp != NULL)
	{
		tmp = get_next_line(map_fd);
		if (tmp == NULL)
			break ;
		if (s_map->index > 0)
		{
			s_map->index--;
			continue ;
		}
		s_map->map[j] = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (s_map->map[j] == NULL)
			return (printf("malloc failed\n"), 1);	
		while (tmp[i])
		{
			s_map->map[j][i] = tmp[i];
			i++;
		}
		s_map->map[j][i] = '\0';
		j++;
		i = 0;
	}
	s_map->map[j] = NULL;
	close (map_fd);
	return (0);
}

int	ft_create_map(char *map_name, int map_fd, t_map *s_map)
{

	while (get_next_line(map_fd) != NULL)
		s_map->y++;
	s_map->y -= s_map->index;
	s_map->map = malloc(sizeof (char *) * (s_map->y + 1));
	if (!s_map->map)
		return (1);
	close (map_fd);
	ft_fill_map(map_name, map_fd, s_map);
	return (0);
}

int	ft_check_map_name(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (!map_name[i])
		return (1);
	return (ft_strcmp(&map_name[i], ".cub"));
}

int	ft_check_valid_map(char *map_name, t_map *s_map)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1 || ft_check_map_name(map_name) != 0)
		return (printf("invalid map_name\n"), 1);
	if (ft_create_map(map_name, map_fd, s_map) == 1)
		return (1);
	if (ft_check_map_composure(s_map->map) == 1)
		return (printf("invalid map composure\n"), 1);
	if (ft_check_map_walls(s_map->map) == 1)
		return (printf("invalid map walls\n"), 1);
	return (0);
}

