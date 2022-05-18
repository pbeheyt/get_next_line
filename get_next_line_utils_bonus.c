/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/19 00:40:44 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if ((unsigned char)c == str[i])
			return (1);
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
