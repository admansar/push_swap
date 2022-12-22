/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/22 13:12:48 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//trouver le minimum
int	min(char **a)
{
	int	i;
	int	min;

	i = 0;
	min = ft_atoi(a[0]);
	while (a[i])
	{
		if (ft_atoi(a[i]) < min)
			min = ft_atoi(a[i]);
		i++;
	}
	return (min);
}

int	max_num(char **b)
{
	int	i;
	int	max;

	i = 0;
	max = ft_atoi(b[0]);
	while (b[i])
	{
		if (ft_atoi(b[i]) > max)
			max = ft_atoi(b[i]);
		i++;
	}
	return (max);
}

//localiser le maximum (position)
unsigned int	snuffer_max(char **a)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	i = 0;
	j = 0;
	k = max_num(a);
	while (a[i])
	{
		if (ft_atoi(a[i]) == k)
			j = i;
		i++;
	}
	return (j);
}

//localiser le minimum (position)
unsigned int	snuffer_min(char **a)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	i = 0;
	j = 0;
	k = min(a);
	while (a[i])
	{
		if (ft_atoi(a[i]) == k)
			j = i;
		i++;
	}
	return (j);
}
