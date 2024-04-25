/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:03:39 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/22 14:58:29 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	// char	line[1024];

	// printf("Sizeof \\0: %ld | %ld\n", sizeof('\0'), sizeof(0));
	// printf("ft_strlen: %ld\n", ft_strlen("123"));

	// line = ft_calloc(128, sizeof(char));
	// fd = open("empty.txt", O_RDONLY);
	// int	ret = read(fd, line, 127);
	// if (!ret)
	// 	return (-1);
	// printf("%s", line);
	// free(line);

	fd = open("test.txt", O_RDWR);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	if (line == NULL)
		printf("NULL\n");
	printf("%s", line);
	free(line);

	// // files/41_no_nl
	// fd = open("gnlTester/files/empty", O_RDONLY);
	// line = get_next_line(fd);
	// if (*line == '\0')
	// 	printf("line = NULL\n");
	// free(line);

	close(fd);
	return (0);
}
