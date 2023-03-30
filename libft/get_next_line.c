/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:57:18 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 00:58:26 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	s = malloc(sizeof(char) * t_strlen(save) - i + 1);
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
		save = t_strjoin(save, ptr);
		if (the_found(save, '\n') == 1)
			break ;
	}
	free(ptr);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd == 1 || fd == 2 || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	save = get_read (fd, save);
	if (!save)
		return (NULL);
	line = get_the_line(save);
	save = get_save(save);
	return (line);
}
