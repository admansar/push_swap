/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:53:05 by admansar          #+#    #+#             */
/*   Updated: 2022/12/10 10:43:27 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*get_save(char *save)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!s)
		return (NULL);
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_the_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	s = malloc(sizeof(char) * i + 1);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_read(int fd, char *save)
{
	int		c;
	char	*ptr;

	c = 1;
	ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (c > 0)
	{
		c = read(fd, ptr, BUFFER_SIZE);
		if (c < 0 && save)
		{
			free(save);
			save = NULL;
			break ;
		}
		else if (c <= 0)
			break ;
		ptr[c] = '\0';
		save = my_join(save, ptr);
		if (the_found(save, '\n') == 1)
			break ;
	}
	free(ptr);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = get_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_the_line(save[fd]);
	save[fd] = get_save(save[fd]);
	return (line);
}
