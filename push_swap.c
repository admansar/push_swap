/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/03/29 23:34:23 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	simple_sort(char **a, char **b, int j, int n)
{
	char	**co;

	co = NULL;
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

void	free_ranger(char **a, char **b, char **sorted)
{
	int	i;

	i = 0;
	while (b[i])
		free(b[i++]);
	free(b);
	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
	i = 0;
	while (sorted[i])
		free(sorted[i++]);
	free(sorted);
	exit(0);
}

void	ranger(char **a, char **b, int chunks)
{
	char	**sorted;
	int		j;

	sorted = sorted_clone(a);
	j = 0;
	while (ft_strcount(a))
	{
		if (ft_atoi(a[0]) <= ft_atoi(sorted[j]))
		{
			pb(&a, &b);
			b = rb(b);
			if (j + chunks < ft_strcount(sorted))
				j++;
		}
		else if (ft_atoi(a[0]) > ft_atoi(sorted[j])
			&& ft_atoi(a[0]) <= ft_atoi(sorted[j + chunks - 1]))
		{
			pb(&a, &b);
			if (j + chunks < ft_strcount(sorted))
				j++;
		}
		else if (ft_strcount(a))
			a = ra(a);
	}
	push_back(a, b, sorted);
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
		ranger(a, b, 35);
	free_exit(a, b, 1, 0);
}
