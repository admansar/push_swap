/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2022/12/21 16:52:09 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to switch the first with the second
char	**switch_1_2(char **c)
{
	char	*tmp;
	int		i;

	i = 0;
	while (c[0][i])
		i++;
	tmp = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (c[0][i++])
		tmp[i] = c[0][i];
	i = 0;
	while (c[1][i])
	{
		c[0][i] = c[1][i];
		i++;
	}
	c[0][i] = '\0';
	i = 0;
	while (tmp[i])
	{
		c[1][i] = tmp[i];
		i++;
	}
	c[1][i] = '\0';
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
	while (c[i])
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
	return (re);
}

//to ecrase the first caractere in the string
char	**ecrase_avant(char **c)
{
	int		i;
	char	**re;

	i = 0;
	while (c[i])
		i++;
	re = malloc(sizeof(char *) * i);
	i = 0;
	while (c[i + 1])
	{
		re[i] = c[i + 1];
		i++;
	}
	re[i] = c[i + 1];
	return (re);
}
