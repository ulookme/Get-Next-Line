/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:10:29 by chajjar           #+#    #+#             */
/*   Updated: 2022/03/25 17:07:43 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		re;

	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	line = NULL;
	re = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (re > 0)
		line = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (re > 0 && buffer[0] != '\n')
	{
		line = ft_strjoin(line, buffer);
		re = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		line = ft_strjoin(line, "\n");
	free(buffer);
	return (line);
}
