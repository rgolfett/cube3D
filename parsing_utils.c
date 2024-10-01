#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

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
	int	i;

	i = 0;
	while (str[i])
	{
		if (!str[i] || str[i] != '.')
			return (1);
		i++;
		if (!str[i] || str[i] != '/')
			return (1);
		return (0);
	}
	return (0);
}