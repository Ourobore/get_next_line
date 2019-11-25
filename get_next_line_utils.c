/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:59:44 by lchapren          #+#    #+#             */
/*   Updated: 2019/11/25 14:52:21 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && buf)
		i++;
	return (i);
}


void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	unsigned char		*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void *alloc;

	alloc = NULL;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((alloc = malloc(count * size)) == NULL)
		return (alloc);
	ft_bzero(alloc, count * size);
	return (alloc);
}

int		get_index(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (i < ft_strlen(buf) && buf[i] != '\n')
		i++;
	if (i == ft_strlen(buf))
		return (-1);
	return (i);
}


char	*ft_strdup(char *s1)
{
	int		i;
	char	*pt_cpy;

	i = 0;
	pt_cpy = NULL;
	if (!(pt_cpy = ft_calloc(sizeof(char), (ft_strlen(s1) + 1))))
		return (pt_cpy);
	while (s1[i])
	{
		pt_cpy[i] = s1[i];
		i++;
	}
	pt_cpy[i] = 0;
	return (pt_cpy);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;
	char	*cat;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(cat = ft_calloc((l + 1),sizeof(char))))
		return (NULL);
	while (j < ft_strlen(s1))
		cat[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		cat[i++] = s2[j++];
	cat[i] = 0;
	free(s1);
	return (cat);
}

char	*get_line(char *REST)
{
	char	*s;
	int		i;

	i = 0;
	while (i < ft_strlen(REST) && REST[i] != '\n' && REST [i] != '\0' && REST[i])
		i++;
	if (!(s = ft_calloc(sizeof(char), (i + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(REST) && REST[i] != '\n' && REST [i] != '\0' && REST[i])
	{
		s[i] = REST[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*get_rest(char *REST)
{
	char	*s;
	int		save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(REST) && REST[i] != '\n' && REST [i] != '\0' && REST[i] && REST)
		i++;
	save = i + 1;
	while (i < ft_strlen(REST) && REST[i] != '\0' && REST[i] && REST)
	{
		i++;
		j++;
	}
	if (!(s = ft_calloc(sizeof(char), (j + 1))))
		return(NULL);
	j = 0;
	i = save;
	while (i < ft_strlen(REST) && REST[i] != '\0' && REST[i] && REST)
		s[j++] = REST[i++];
	s[j] = 0;
	free(REST);
	return (s);
}
