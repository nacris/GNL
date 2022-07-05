/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncriscia <natashacriscia@yahoo.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:10:58 by ncriscia          #+#    #+#             */
/*   Updated: 2022/07/04 18:25:08 by ncriscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *str)
{
	int		i;
	char	*s1;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	s1 = malloc(sizeof(char) * (i + 2));
	if (!s1)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s1[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s1[i++] = '\n';
	s1[i] = '\0';
	return (s1);
}

static char	*ft_rest(char *str)
{
	int		i;
	char	*rest;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	rest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (0);
	i++;
	j = 0;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

static char	*ft_gnl(char *str, int fd)
{
	int		i;
	char	*s;

	i = 1;
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i < 0)
		{
			free (s);
			return (NULL);
		}
		s[i] = '\0';
		if (!str)
		{
			str = malloc(1 * sizeof(char));
			*str = 0;
		}
		str = ft_strjoin(str, s);
	}
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*rec;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	str = ft_gnl(str, fd);
	if (!str)
		return (0);
	rec = ft_line(str);
	str = ft_rest(str);
	return (rec);
}
