/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:18 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/05/19 02:29:11 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*clear_save(char *save);
char	*extract_line(char *save);
char	*read_and_add(char *save, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif