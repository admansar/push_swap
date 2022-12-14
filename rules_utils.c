/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2022/12/13 18:16:00 by admansar         ###   ########.fr       */
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
	tmp = malloc(sizeof(char) * i + 1);
	i = 0;
	while (c[0][i])
	{
		tmp[i] = c[0][i];
		i++;
	}
	tmp[i] = '\0';
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
	//free(c);
	return (re);
}
//rotate first to last
//you should affect
char	**rftl(char **a)
{
	int		i;
	char	**re;

	i = 0;
	re = ft_calloc(ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		re[i] = a[i];
		i++;
	}
	re[i] = a[0];
	re = ecrase_avant(re);
	return (re);
}
//rotate in the sense off integral of cos
char	**reverse_rotate(char **a)
{
	char	**re;
	int		i;

	i = 0;
	re = malloc((ft_strcount(a) + 1) * sizeof(char *));
	re[0] = a[ft_strcount(a) - 1];
	while (a[i])
	{
		re[i + 1] = a[i];
		i++;
	}
	re[i] = a[i];
	return (re);
}
