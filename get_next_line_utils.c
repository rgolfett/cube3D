/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:35:13 by rgolfett          #+#    #+#             */
/*   Updated: 2024/01/03 14:51:00 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1 || s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (str);
}

char	*ft_move(char *dest, char *src)
{
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (dest[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	cpy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		cpy[i] = '\0';
		i++;
	}
	str = (cpy);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*cpy2;
	size_t			i;

	cpy = (unsigned char *)src;
	cpy2 = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return ((void *)dest);
	while (i < n)
	{
		cpy2[i] = cpy[i];
		i++;
	}
	cpy2[i] = '\0';
	return (dest);
}
