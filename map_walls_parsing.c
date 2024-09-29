#include "cube_3D.h"
#include "get_next_line.h"

int	ft_walls_utils(char **map, int i, int j)
{
	if (map[i][j] == '0')
	{
		if (!map[i-1][j] || map[i-1][j] == '\n' || map[i-1][j] == ' ')//haut
			return (printf("map[%i][%i] = invalid upper walls : *%c*\n", i, j, map[i-1][j]), 1);
		if (!map[i+1][j] || map[i+1][j] == '\n' || map[i+1][j] == ' ')//bas
			return (printf("map[%i][%i] = invalid bottom walls : *%c*\n", i, j, map[i+1][j]), 1);
		if (!map[i][j+1] || map[i][j+1] == '\n' || map[i][j+1] == ' ')//droite
			return (printf("map[%i][%i] = invalid right walls : *%c*\n", i, j, map[i][j+1]), 1);
		if (!map[i][j-1] || map[i][j-1] == '\n' || map[i][j-1] == ' ')//gauche
			return (printf("map[%i][%i] = invalid left walls : *%c*\n", i, j, map[i][j-1]), 1);
	}
	return (0);
}

int	ft_check_map_walls(char **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' /*&& map[i][j] != '\n'*/)
			{
				if (map[i][j] == '0' && (j == 0 || i == 0))
					return (printf("wrong walls, out of bounds\n"), 1);
				if (ft_walls_utils(map, i, j) == 1)
					return (printf("-invalid walls-\n"), 1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
