/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/03/28 18:07:46 by admansar         ###   ########.fr       */
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
	if (ft_atoi((*a)[0]) > ft_atoi((*a)[1]) && ft_atoi((*a)[1]) > ft_atoi((*a)[2]))
	{
		sa((*a));
		(*a) = rra((*a));
	}
	else if (ft_atoi((*a)[2]) > ft_atoi((*a)[0]) && ft_atoi((*a)[0]) > ft_atoi((*a)[1]))
	{
		sa((*a));
	}
	else if (ft_atoi((*a)[0]) > ft_atoi((*a)[1]) && ft_atoi((*a)[2]) > ft_atoi((*a)[1]))
	{
		(*a) = ra((*a));
	}
	else if (ft_atoi((*a)[1]) > ft_atoi((*a)[2]) && ft_atoi((*a)[2]) > ft_atoi((*a)[0]))
	{
		pb(&(*a), &b);
		sa((*a));
		pa(&(*a), &b);
	}
	else
		(*a) = rra((*a));
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
	free_exit(a, b, 1, 1);
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
