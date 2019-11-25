/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:00:13 by lchapren          #+#    #+#             */
/*   Updated: 2019/11/25 11:52:57 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

static char *REST;

int     get_next_line(int fd, char **line);
int     get_index(char *buf);
int     ft_strlen(char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char    *get_line(char *REST);
char	*get_rest(char *REST);
void	*ft_calloc(size_t count, size_t size);

#endif
