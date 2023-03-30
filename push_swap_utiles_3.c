/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/03/29 23:02:52 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**ft_str_pro_cpy(char **re, char **a)
{
	int	i;
	int	h;

	re = ft_calloc(ft_strcount(a) + 1, sizeof(char *));
	i = 0;
	while (a[i])
	{
		h = ft_strlen(a[i]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], a[i], h);
		i++;
	}
	i = 0;
	while (a[i])
	{
		free(a[i]);
		a[i] = NULL;
		i++;
	}
	free(a);
	a = NULL;
	return (re);
}

char	**case_of_3(char ***a, char **b)
{
	if (ft_atoi((*a)[0]) > ft_atoi((*a)[1])
		&& ft_atoi((*a)[1]) > ft_atoi((*a)[2]))
	{
		sa((*a));
		(*a) = rra((*a));
	}
	else if (ft_atoi((*a)[2]) > ft_atoi((*a)[0])
			&& ft_atoi((*a)[0]) > ft_atoi((*a)[1]))
		sa((*a));
	else if (ft_atoi((*a)[0]) > ft_atoi((*a)[1])
			&& ft_atoi((*a)[2]) > ft_atoi((*a)[1]))
		(*a) = ra((*a));
	else if (ft_atoi((*a)[1]) > ft_atoi((*a)[2])
			&& ft_atoi((*a)[2]) > ft_atoi((*a)[0]))
	{
		pb(&(*a), &b);
		sa((*a));
		pa(&(*a), &b);
	}
	else
		(*a) = rra((*a));
	free(b);
	return (NULL);
}

int	number_still_inside(char **a, int ke)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (ft_atoi(a[i]) <= ke)
			return (1);
		i++;
	}
	return (0);
}

void	push_back(char **a, char **b, char **sorted)
{
	int	i;
	int	j;

	i = ft_strcount(b);
	while (i)
	{
		j = snuffer_max(b);
		if (j == 0)
			pa(&a, &b);
		else if (j >= i / 2)
		{
			b = rrb(b);
		}
		else
			b = rb(b);
	i = ft_strcount(b);
	}
	free_ranger(a, b, sorted);
}

char	**the_clone(char **c)
{
	char	**a;
	int		i;

	i = 0;
	a = ft_calloc(sizeof(char *), (ft_strcount(c) + 1));
	while (c[i])
	{
		ft_strlcpy(a[i], c[i], ft_strlen(c[i]) + 1);
		i++;
	}
	return (a);
}
