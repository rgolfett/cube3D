
#include "cube_3D.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*cpy;

	i = 0;
	cpy = malloc((sizeof (char)) * (ft_strlen(s) + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_zero(void)
{
	char	*zero;

	zero = malloc(sizeof(char) * 2);
	if (!zero)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

static int	ft_size_nb(int n)
{
	int	cmpt;

	cmpt = 0;
	if (n < 0)
	{
		n *= -1;
		cmpt++;
	}
	while (n > 0)
	{
		n /= 10;
		cmpt++;
	}
	return (cmpt);
}

static char	*ft_fill(char *tab, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		tab[0] = '-';
		i++;
	}
	i += ft_size_nb(n);
	tab[i] = '\0';
	i--;
	while (n > 0)
	{
		tab[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;

	if (n == 0)
		return (ft_zero());
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = malloc(sizeof(char) *(ft_size_nb(n) + 1));
	if (!tab)
		return (NULL);
	return (ft_fill(tab, n));
}