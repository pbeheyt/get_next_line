/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/13 04:10:27 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	unsigned int	j;

	if (str == 0)
		return (0);
	j = 0;
	while (str[j] != 0)
	{
		if ((unsigned char)c == str[j])
			return (1);
	j++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s1 == 0 && s2 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s1 && *s1 != 0)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2 != 0)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	return (str);
}
