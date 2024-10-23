/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:39:17 by rgolfett          #+#    #+#             */
/*   Updated: 2024/10/23 15:13:43 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_line(char *buff)
{
	ssize_t	i;

	i = 0;
	if (!buff || buff[0] == '\0')
		return (-1);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	else
		return (-1);
}

char	*ft_line(char *str)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!*str)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	dest[i] = '\0';
	return (dest);
}

char	*crush_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ft_memmove(str, &str[i], ft_strlen(&str[i]));
	return (str);
}

char	*ft_zero_fill(char *str, size_t n)
{
	size_t	i;

	str = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < (n + 1))
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0";
	char		*str;
	ssize_t		iread;
	char		*tmp;

	str = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	iread = 1;
	while (ft_get_line(buff) == -1 && iread > 0)
	{
		str = ft_strjoin(str, buff);
		ft_bzero(buff, BUFFER_SIZE);
		iread = read(fd, buff, BUFFER_SIZE);
		if (iread == -1)
			return (free (str), NULL);
	}
	if (iread != 0)
		str = ft_strjoin(str, buff);
	tmp = ft_line(str);
	crush_line (buff);
	free (str);
	return (tmp);
}
