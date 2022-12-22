/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/22 18:24:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**sorted_clone(char **c)
{
	char	**a;
	int		i;
	char	*tmp;

	i = 0;
	a = ft_calloc(sizeof(char *), (ft_strcount(c) + 1));
	while (c[i])
	{
		a[i] = c[i];
		i++;
	}
	i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
		{
			tmp = malloc(sizeof(char) * (ft_strlen(a[i]) + 1));
			tmp = a[i];
			a[i] = a[i - 1];
			a[i - 1] = tmp;
			i = 1;
		}
		i++;
	}
	return (a);
}

int	next_num(char **a, int xhal)
{
	int			j;
	static int	b;

	j = ft_strcount(a) / xhal;
	b += j;
	if (b > ft_strcount(a))
		b = ft_strcount(a) - 1;
	return (ft_atoi(a[b]));
}

char	**needed_clone(char **a, int ke)
{
	int		i;
	char	**re;

	i = 0;
	re = malloc(sizeof(char *) * (ke + 1));
	while (i <= ke)
	{
		re[i] = a[i];
		i++;
	}
	re[i] = NULL;
	return (re);
}

//to make sure that everything is done (return 1 if everything cool)
int	done(char **a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
			return (0);
		i++;
	}
	return (1);
}

int	done_b(char **b)
{
	int	i;

	i = 1;
	while (b[i])
	{
		if (ft_atoi(b[i - 1]) < ft_atoi(b[i]))
			return (0);
		i++;
	}
	return (1);
}
