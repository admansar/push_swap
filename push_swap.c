/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/01/01 04:19:51 by admansar         ###   ########.fr       */
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
//	the_writer(re, re); 
	return (a);
}

void	simple_sort(char **a, char **b, int j, int n)
{
	char	**co;
	int		total;

	while (!(done(a) == 1))
	{
		total = ft_strcount(a);
		j = snuffer_min(a);
		if (total == 3)
		{
			co = ft_str_pro_cpy(NULL, b);
			a = ft_str_pro_cpy(NULL, case_of_3(a, co));
			b = ft_str_pro_cpy(NULL, co);
		}
		else if (j == 0)
		{
			pb(&a, &b);
		}
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
	{
		pa(&a, &b);
	}
		free_exit(a, b, 1, 1);
}

void	case_(char **a, char **b, int c)
{
	int	i;
	int	ke;
	char **so;

	i = 0;
	ke = 0;
	while (ke != ft_strcount(a) - 1 && ft_strcount(a))
	{
		so = sorted_clone(a);
		ke = next_num(so, c / 10);
		while (number_still_inside(a, ke))
		{
			if (ft_atoi(a[0]) <= ke)
			{
				pb(&a, &b);
			}
			else
			{
				a = ra(a);
			}
		}
		while (so[i])
		{
			free(so[i]);
			so[i] = NULL;
			i++;
		}
		free(so);
		so = NULL;
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
	if (i2 == 1)
	free(b);
	b = NULL;
//	while(1){};
	exit(0);
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
	}
	else if (total == 3)
	{
		a = case_of_3(a, b);
	free_exit(a, b, 1, 0);
	//	while(1){};
	}
	else if (total < 100)
	{
		simple_sort(a, b, 0, 0);
	}
	else if (total < 500)
		case_(a, b, 200);
	else
		case_(a, b, 540);
	free_exit(a, b, 1, 1);
}
