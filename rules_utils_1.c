/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2023/03/27 16:33:09 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to switch the first with the second
char	**switch_1_2(char **c)
{
	char	*tmp;

	tmp = ft_calloc(sizeof(char), ft_strlen(c[0]) + 1);
	ft_strlcpy(tmp, c[0], ft_strlen(c[0]) + 1);
	ft_strlcpy(c[0], c[1], ft_strlen(c[1]) + 1);
	ft_strlcpy(c[1], tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (c);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_strcount(char **c)
{
	int	i;

	i = 0;
	while (c[i] && c)
		i++;
	return (i);
}

char	**first_to_first(char **a, char **b)
{
	int		i;
	int		j;
	char	**re;

	i = 0;
	j = 0;
	re = ft_calloc(sizeof(char *), ft_strcount(b) + 2);
	while (b[j])
	{
		re[j + 1] = ft_calloc(ft_strlen(b[j]) + 1, sizeof(char));
		ft_strlcpy(re[j + 1], b[j], ft_strlen(b[j]) + 1);
		j++;
	}
	while (b[i])
	{
		free(b[i]);
		b[i] = NULL;
		i++;
	}
	free(b);
	b = NULL;
	re[0] = ft_calloc(ft_strlen(a[0]) + 1, sizeof(char));
	ft_strlcpy(re[0], a[0], ft_strlen(a[0]) + 1);
	return (re);
}

//to ecrase the first caractere in the string
char	**ecrase_avant(char **c)
{
	int		i;
	char	**re;
	int		h;

	i = ft_strcount(c);
	re = ft_calloc(sizeof(char *), i);
	i = 0;
	while (c[i + 1])
	{
		h = ft_strlen(c[i + 1]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], c[i + 1], h);
		i++;
	}
	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = NULL;
		i++;
	}
	free(c);
	c = NULL;
	return (re);
}
/*
char	**first_to_first(char **a, char **b)
{
	int		i;
	int		j;
	char	**re;

	i = 0;
	j = 0;
	while (b[i])
		i++;
	re = ft_calloc(sizeof(char *), i + 2);
	while (j < i)
	{
		re[j + 1] = b[j];
		j++;
	}
	re[0] = a[0];
	re[j + 1] = 0;
	if (b == malloc(ft_strcount(b)))
		free(b);
	return (re);
}
*/
