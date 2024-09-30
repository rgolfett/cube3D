
#include "cube_3D.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	t_arg arg;
	arg = (t_arg){0};

	if (argc != 2)
		return (1);
	if (check_file(argv[1], &arg) == 1)
		return (1);
	int i = 0;
	while (arg.content[i])
	{
		printf("content[%i] = %s\n", i, arg.content[i]);
		i++;
	}
	if (ft_check_valid_map(argv[1], &arg.s_map) == 1)
		return (1);
	ft_test();
}