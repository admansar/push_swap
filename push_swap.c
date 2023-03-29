/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/03/29 01:27:28 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	simple_sort(char **a, char **b, int j, int n)
{
	char	**co = NULL;

	while (!(done(a) == 1))
	{
		j = snuffer_min(a);
		if (ft_strcount(a) == 3)
		{
			co = ft_calloc(1, sizeof(char *));
			case_of_3(&a, co);
		}
		else if (j == 0)
			pb(&a, &b);
		else if (j == 1)
		{
			sa(a);
			pb(&a, &b);
		}
		else
			a = norm_(a, n, ft_strcount(a), j);
	}
	while (ft_strcount(b))
		pa(&a, &b);
	free_exit(a, b, 1, 1);
}

void	case_(char **a, char **b, int c)
{
	int		i;
	int		ke;
	char	**so;

	i = 0;
	ke = 0;
	while (ke != ft_strcount(a) - 1 && ft_strcount(a))
	{
		so = sorted_clone(a);
		ke = next_num(so, c / 10);
		while (number_still_inside(a, ke))
		{
			if (ft_atoi(a[0]) <= ke)
				pb(&a, &b);
			else
				a = ra(a);
		}
		while (so[i])
			free(so[i++]);
		free(so);
		i = 0;
	}
	push_back(a, b);
}

void	free_exit(char **a, char **b, int i1, int i2)
{
	int	i;

	if (i1 == 1)
	{
		i = 0;
		while (a[i])
		{
			free(a[i]);
			a[i] = NULL;
			i++;
		}
	}
	free(a);
	if (i2 == 1)
		free(b);
	b = NULL;
	exit(0);
}

void	ranger(char **a, char **b, int chunks)
{
	char	**sorted;
	int		i;
	int		j;

	sorted = sorted_clone(a);
	i = 0;
	j = 0;
	while (ft_strcount(a))
	{
		if (ft_atoi(a[i]) <= ft_atoi(sorted[j]))
		{
			pb(&a, &b);
			b = rb(b);
			if (j + chunks < ft_strcount(sorted))
			j++;
		}
		else if (ft_atoi(a[i]) > ft_atoi(sorted[j]) && ft_atoi(a[i]) <= ft_atoi(sorted[j + chunks - 1]))
		{
			pb(&a, &b);
			if (j + chunks < ft_strcount(sorted))
			j++;
		}
		else if (ft_strcount(a)) 
		{
			a = ra(a);
		}
	}
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
	free_exit(a, b, 1, 0);
}

void	push_swap(char **a, char **b)
{
	int	total;

	total = ft_strcount(a);
	if (done(a) == 1)
		free_exit(a, b, 1, 1);
	else if (total == 2)
	{
		if (!(done(a) == 1))
			sa(a);
		free_exit(a, b, 1, 1);
	}
	else if (total == 3)
	{
		case_of_3(&a, b);
		free_exit(a, b, 1, 0);
	}
	else if (total <= 20)
	{
		simple_sort(a, b, 0, 0);
	}
	else if (total <= 100) 
		ranger(a, b, 15);
	else
		ranger(a, b, 30);
}
