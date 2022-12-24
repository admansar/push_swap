/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/24 17:03:08 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**case_of_3(char **a, char **b)
{
	if (ft_atoi(a[0]) > ft_atoi(a[1]) && ft_atoi(a[1]) > ft_atoi(a[2]))
	{
		sa(a);
		a = rra(a);
	}
	else if (ft_atoi(a[2]) > ft_atoi(a[0]) && ft_atoi(a[0]) > ft_atoi(a[1]))
	{
		sa(a);
	}
	else if (ft_atoi(a[0]) > ft_atoi(a[1]) && ft_atoi(a[2]) > ft_atoi(a[1]))
	{
		a = ra(a);
	}
	else if (ft_atoi(a[1]) > ft_atoi(a[2]) && ft_atoi(a[2]) > ft_atoi(a[0]))
	{
		pb(&a, &b);
		sa(a);
		pa(&a, &b);
	}
	else
	{
		a = rra(a);
	}
	return (a);
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

void	push_back(char **a, char **b)
{
	while (ft_strcount(b))
	{
		if (snuffer_max(b) == 0)
		{
			pa(&a, &b);
		}
		else
		{
			if ((int)snuffer_max(b) < (ft_strcount(b) / 2) + 1)
			{
				while (snuffer_max(b))
				{
					b = rb(b);
				}
			}
			else
			{
				while (snuffer_max(b))
				{
					b = rrb(b);
				}
			}
		}
	}
}

char	**norm_ra(char **a, int n, int j)
{
	while (n < (int)j--)
	{
		if (done(a) == 1)
			break ;
		a = ra(a);
	}
	return (a);
}

char	**the_clone(char **c)
{
	char	**a;
	int		i;

	i = 0;
	a = ft_calloc(sizeof(char *), (ft_strcount(c) + 1));
	while (c[i])
	{
		a[i] = c[i];
		i++;
	}
	return (a);
}
