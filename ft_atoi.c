#include "cube_3D.h"
#include "get_next_line.h"
#include "minilibx-linux/mlx.h"

long	ft_strtol(const char *p)
{
	long	nbr;
	int		i;
	int		signe;

	nbr = 0;
	i = 0;
	signe = 1;
	while ((p[i] >= 9 && p[i] <= 13) || p[i] == 32)
		i++;
	if (p[i] == '-' || p[i] == '+')
		if (p[i++] == '-')
			signe = -1;
	while (ft_isdigit(p[i]))
	{
		if (nbr != ((nbr * 10) + (p[i] - '0')) / 10)
		{
			if (signe == -1)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		nbr = (nbr * 10) + (p[i] - '0');
		i++;
	}
	printf("nbr = %i\n", i);
	return (nbr * signe);
}
static int	ft_overflow(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

static long	ft_calc(char *str, int i, int sign)
{
	long	nbr;

	nbr = 0;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	while (str[i] && str[i] == 48)
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if (nbr * 10 + (str[i] - 48) < nbr)
			return (ft_overflow(sign));
		nbr *= 10;
		nbr += ((str[i] - 48));
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		i;
	char	*str2;
	int		nbr1;
	int		sign;

	i = 0;
	str2 = (char *) str;
	nbr1 = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr1 = ft_calc(str2, i, sign);
	return (nbr1 * sign);

}