/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:56:47 by lchapren          #+#    #+#             */
/*   Updated: 2019/11/25 15:17:54 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char *buf;
	int end;

	end = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	buf[BUFFER_SIZE] = 0;
	while (get_index(REST) == -1 && (end = read(fd, buf, BUFFER_SIZE)))
	{
		if (end == -1)
			return (-1);
		REST = ft_strjoin(REST, buf);
	}
	if (REST && end == 0)
	{
		*line = get_line(REST);
		REST = get_rest(REST);
		//printf("line EOF: %s \n", *line);
		free(buf);
		return (0);
	}
	else
	{
		if (end < 0)
			return (-1);
		else
		{
			if (REST[0] == '\n')
			{
				if (!(*line = malloc(1)))
					return (-1);
				*line[0] = '\0';
				//printf("line R:%s\n", *line);
				REST = get_rest(REST);
				free(buf);
				return (1);
			}
			else
			{
				//index = get_index(REST);
				*line = get_line(REST);
				//printf("line: %s \n", *line);
				REST = get_rest(REST);
				free(buf);
				return (1);
			}
		}
	}
	return (0);
}

int main()
{
	char *line;
	int fd = open("doc", O_RDONLY);

	printf("%d\n", get_next_line(fd, &line));
	free(line);
	printf("%d\n", get_next_line(fd, &line));
	free(line);
	printf("%d\n", get_next_line(fd, &line));
	free(line);
	printf("%d\n", get_next_line(fd, &line));
	free(line);

	close(fd);
}
