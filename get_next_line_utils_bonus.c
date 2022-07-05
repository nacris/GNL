/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncriscia <natashacriscia@yahoo.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:13:42 by ncriscia          #+#    #+#             */
/*   Updated: 2022/07/02 20:35:38 by ncriscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (0);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[j] != '\0')
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	k;

	k = (unsigned char) c;
	if (!s)
	{
		free(s);
		return (0);
	}
	while (*s != '\0')
	{
		if (*s == k)
			return ((char *)s);
		s++;
	}
	if (*s == k)
		return ((char *)s);
	return (0);
}
