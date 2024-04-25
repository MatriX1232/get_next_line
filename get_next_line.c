/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:01:29 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/25 15:16:29 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_transfer(char *base, char *addition)
{
	char	*new;

	new = ft_strjoin(base, addition);
	if (!new)
		return (NULL);
	free(base);
	return (new);
}

char	*ft_move_offset(char *buffer)
{
	int		index;
	int		i;
	char	*new;

	if (*buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	new = ft_calloc(ft_strlen(buffer) - index + 1, sizeof(char));
	if (!new)
		return (NULL);
	index++;
	i = 0;
	while (buffer[index + i])
	{
		new[i] = buffer[index + i];
		i++;
	}
	new[i] = '\0';
	free(buffer);
	return (new);
}

char	*ft_extract_line(char *buffer)
{
	int		index;
	int		i;
	char	*line;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < index && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[index] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_readline(int fd, char *buffer_all)
{
	int		bytes_read;
	char	*buffer;

	if (!buffer_all)
		buffer_all = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		buffer_all = ft_transfer(buffer_all, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_all);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_move_offset(buffer);
	return (line);
}
