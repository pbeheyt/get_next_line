/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/13 04:13:41 by pbeheyt          ###   ########.fr       */
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
	if (save[i] == 0)
		return (free(save), 0);
	save_cleared = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (save_cleared == 0)
		return (free(save), 0);
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

	if (*save == 0)
		return (0);
	i = 0;
	while (save[i] != '\n' && save[i] != 0)
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (line == 0)
		return (free(line), 0);
	line[++i] == 0;
	while (i--)
		line[i] = save[i];
	return (line);
}

char	*read_and_add(char *save, int fd)
{
	char	*buffer;
	int		readbytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	readbytes = 1;
	while (ft_strchr(save, '\n') == 0 && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(buffer), free(save), 0);
		buffer[readbytes] = 0;
		save = ft_strjoin(save, buffer);
	}
	return (free(buffer), save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_and_add(save, fd);
	if (save == 0)
		return (0);
	line = extract_line(save);
	save = clear_save(save);
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
		if (line == 0)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
