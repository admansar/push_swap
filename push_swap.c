/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/15 16:38:36 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//to make sure that everything is done (return 1 if everything cool)
int done(char **a)
{
	int i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
			return (0);
		i++;
	}
	return (1);
}
//trouver le minimum
int min(char **a)
{
	int i = 0;
	int min = ft_atoi(a[0]);
	while(a[i])
	{
		if (ft_atoi(a[i]) < min)
			min = ft_atoi(a[i]);
	i++;
	}
	return (min);
}
//localiser le minimum (position)
unsigned int snuffer(char **a)
{
	unsigned int i = 0;
	unsigned int j = 0;
	int k = min(a);
	while (a[i])
	{
		if (ft_atoi(a[i]) == k)
			j = i;
		i++;
	}
	return (j);
}

void push_swap(char **a, char **b)
{
	unsigned int j;
	int n = 0;
	int total = ft_strcount(a);
	//the_writer(a, b);
	while (!(done(a) == 1))
	{
		j = snuffer(a);
		if (j == 0)
		{
			pb(&a, &b);
	//		the_writer(a, b);
		}
		else if (j < (total / 2))
		{
			while (n < j)
			{
				if (snuffer(a) == 0)
					break ;
				a = ra(a);
				j--;
				//the_writer(a, b);
			}
		}
		else
		{
			while (total > j)
			{
				if (snuffer(a) == 0)
					break;
				a = rra(a);
				j++;
				//the_writer(a,b);
			}
		}
		
	}
	n = 0;
	j = ft_strcount(b);
	while (n < j)
	{
		pa(&a,&b);
	//the_writer(a,b);
		n++;
	}
}
