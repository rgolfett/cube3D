
#include "cube_3D.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	i;
	t_map s_map;

	i = 0;
	s_map = (t_map){0};
	if (argc == 1)
		return (1);
	while (argv[i] != NULL)
		i++;
	if (ft_check_valid_map(argv[i-1], &s_map) == 1)
		return (1);
	ft_test();
}