/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:19:40 by hatesfam          #+#    #+#             */
/*   Updated: 2023/02/16 17:52:44 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_buffer(int fd, char *buff)
{
	char	*buffer;
	int		byte_read;

	if (!buff)
		buff = ft_calloc(1, 1);
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (!(ft_strchr(buffer, '\n')) && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		buff = ft_strjoin(buff, buffer);
	}
	free(buffer);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd1);
		if (line)
			printf("line [%d]: %s", i, line);
		line2 = get_next_line(fd2);
		if (line2)
			printf("line [%d]: %s", i, line2);
		line3 = get_next_line(fd3);
		if (line3)
			printf("line [%d]: %s", i, line3);
		if (!line)
			break ;
		free(line);
		free(line2);
		free(line3);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/