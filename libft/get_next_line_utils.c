/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:49:20 by admansar          #+#    #+#             */
/*   Updated: 2022/12/10 10:43:12 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*c;

	i = 0;
	c = (char *)malloc(sizeof(char) *(ft_strlen(s) + 1));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	the_found(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*my_join(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*ptr;

	i = 0;
	n = 0;
	if (!s1)
		return (ft_strdup(s2));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		ptr[i + n] = s2[n];
		n++;
	}
	ptr[i + n] = '\0';
	free(s1);
	return (ptr);
}
