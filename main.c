
#include "cube_3D.h"
#include "get_next_line.h"

void	ft_print_all(t_arg *arg)
{
	int	i = 0;
	while (arg->content[i])
	{
		printf("content[%i] = %s\n", i, arg->content[i]);
		i++;
	}
	printf("\n\n");
	printf("n = %s\n", arg->NO_file);
	printf("e = %s\n", arg->EA_file);
	printf("w = %s\n", arg->WE_file);
	printf("s = %s\n", arg->SO_file);
	printf("index = %i\n",arg->s_map.index);
	printf("arg->floor-> R = %i\n", arg->floor.R);
	printf("arg->floor-> G = %i\n", arg->floor.G);
	printf("arg->floor-> B = %i\n", arg->floor.B);
	printf("arg->ceiling-> R = %i\n", arg->ceiling.R);
	printf("arg->ceiling-> G = %i\n", arg->ceiling.G);
	printf("arg->ceiling-> B = %i\n", arg->ceiling.B);
	printf("\n\n");
}
void	free_utils(t_arg *arg)
{
	if (arg->NO_file)
		free(arg->NO_file);
	if (arg->EA_file)
		free(arg->EA_file);
	if (arg->WE_file)
		free(arg->WE_file);
	if (arg->SO_file)
		free(arg->SO_file);
	if (arg->content)
		free_str(arg->content);
	if (arg->s_map.map)
		free_str(arg->s_map.map);
	if (arg->s_map.map_name)
		free(arg->s_map.map_name);
}
int main(int argc, char **argv)
{
	t_arg arg;
	arg = (t_arg){0};

	arg.ceiling = (t_color){-2};
	arg.floor = (t_color){-2};
	if (argc != 2)
		return (1);
	
	if (check_file(argv[1], &arg) == 1)
		return (1);

	ft_print_all(&arg);
	//arg.s_map.index += 3;//
	if (ft_check_valid_map(argv[1], &arg.s_map) == 1)
		return (1);
	free_utils(&arg);
	ft_test();
}
