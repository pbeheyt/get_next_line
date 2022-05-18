/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/19 01:52:06 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_save(char *save)
{
	int		i;
	int		j;
	char	*save_cleared;

	i = 0;
	while (save[i] != 0 && save[i] != '\n' )
		i++;
	if (!save[i])
		return (free(save), NULL);
	save_cleared = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!save_cleared)
		return (free(save), NULL);
	i++;
	j = 0;
	while (save[i] != 0)
		save_cleared[j++] = save[i++];
	save_cleared[j] = 0;
	return (free(save), save_cleared);
}

char	*extract_line(char *save)
{
	char	*line;
	size_t	i;

	if (!*save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (free(line), NULL);
	line[++i] = 0;
	while (i--)
		line[i] = save[i];
	return (line);
}

char	*read_and_add(char *save, int fd)
{
	char	*buffer;
	char	*tmp;
	int		readbytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(save, '\n') && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(buffer), free(save), NULL);
		buffer[readbytes] = 0;
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = tmp;
	}
	return (free(buffer), save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = read_and_add(save[fd], fd);
	if (!save[fd])
		return (NULL);
	line = extract_line(save[fd]);
	save[fd] = clear_save(save[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}*/