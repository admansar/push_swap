/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/22 13:15:00 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**norm_rra(char **a, int total, int j)
{
	while (total > (int)j++)
	{
		if (done(a) == 1)
			break ;
		a = rra(a);
	}
	return (a);
}

void	simple_sort(char **a, char **b, int j, int n)
{
	int	total;

	while (!(done(a) == 1))
	{
		total = ft_strcount(a);
		j = snuffer_min(a);
		if (total == 3)
			a = case_of_3(a, b);
		else if (j == 0)
			pb(&a, &b);
		else if (j == 1)
		{
			sa(a);
			pb(&a, &b);
		}
		else if ((int)j < (total / 2) + 1)
			a = norm_ra(a, n, j);
		else
			a = norm_rra(a, total, j);
	}
	while (ft_strcount(b))
		pa(&a, &b);
}

void	case_(char **a, char **b, int c)
{
	int	i;
	int	ke;

	i = 0;
	ke = 0;
	while (ke != ft_strcount(a) - 1 && ft_strcount(a))
	{
		ke = next_num(sorted_clone(a), c / 10);
		while (number_still_inside(a, ke))
		{
			if (ft_atoi(a[i]) <= ke)
			{
				pb(&a, &b);
			}
			else
			{
				a = ra(a);
			}
		}
	}
	push_back(a, b);
}

void	free_exit(char **a, char **b)
{
	free(a);
	free(b);
	exit(0);
}

void	push_swap(char **a, char **b)
{
	int	total;

	total = ft_strcount(a);
	if (done(a) == 1)
		free_exit(a, b);
	else if (total == 2)
	{
		if (!(done(a) == 1))
			sa(a);
	}
	else if (total == 3)
		a = case_of_3(a, b);
	else if (total < 100)
		simple_sort(a, b, 0, 0);
	else if (total < 500)
		case_(a, b, 100);
	else
		case_(a, b, 500);
	free_exit(a, b);
}
