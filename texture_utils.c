
#include "cube_3D.h"

int	is_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_fill_arg(char *file_name, int file_fd, t_arg *arg)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = "0";
	file_fd = open(file_name, O_RDONLY);
	while (tmp != NULL)
	{
		tmp = get_next_line(file_fd);
		if (tmp == NULL)
			break ;
		arg->content[j] = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (arg->content[j] == NULL)
			return (free_str(arg->content), 1);	
		while (tmp[i])
		{
			arg->content[j][i] = tmp[i];
			i++;
		}
		arg->content[j][i] = '\0';
		j++;
		i = 0;
	}
	arg->content[j] = NULL;
	close (file_fd);
	return (0);
}

int	ft_create_arg(char *file_name, int file_fd, t_arg *arg)
{

	while (get_next_line(file_fd) != NULL)
		arg->lines++;
	arg->content = malloc(sizeof (char *) * (arg->lines + 1));
	if (!arg->content)
		return (1);
	close (file_fd);
	ft_fill_arg(file_name, file_fd, arg);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}