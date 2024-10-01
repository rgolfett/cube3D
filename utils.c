#include "cube_3D.h"
#include "get_next_line.h"

int	ft_is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'W' && c != 'S' && c != 'E'&& c != 'N'\
			&& c != ' ' && c != '\n')
		return (1);
	return (0);
}
int	ft_nmb_player(char c, int cmp)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		cmp += 1;
	return (cmp);
}

int	ft_cpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2 == NULL)
		return (1);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (0);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_memset(int *tab, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		tab[i] = c;
		i++;
	}
}

// void	*ft_memset(void *str, int c, size_t size)
// {
// 	char *cpy;

// 	cpy = str;
// 	while (size)
// 	{
// 		*cpy = (unsigned char)c;
// 		cpy++;
// 		size--;
// 	}
// 	return (str);
// }