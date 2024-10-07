
#include "cube_3D.h"

int	get_color(int r, int g, int b)
{
	char *tmp;

	printf("r = %s\n", ft_itoa(r));
	tmp = ft_strjoin(ft_itoa(r), ft_itoa(g));
	tmp = ft_strjoin(tmp, ft_itoa(b));

	printf("tmp = %s\n", tmp);

}