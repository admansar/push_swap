/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/17 20:26:13 by admansar         ###   ########.fr       */
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
int done_b(char **b)
{
	int i = 1;
	while (b[i])
	{
		if (ft_atoi(b[i - 1]) < ft_atoi(b[i]))
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
int max_num(char **b)
{
	int i = 0;
	int max = ft_atoi(b[0]);
	while (b[i])
	{
		if (ft_atoi(b[i]) > max)
			max = ft_atoi(b[i]);
		i++;
	}
	return (max);
}
//localiser le maximum (position)
unsigned int snuffer_max(char **a)
{
	unsigned int i = 0;
	unsigned int j = 0;
	int k = max_num(a);
	while (a[i])
	{
		if (ft_atoi(a[i]) == k)
			j = i;
		i++;
	}
	return (j);
}
//localiser le minimum (position)
unsigned int snuffer_min(char **a)
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
char **case_of_3(int total, char **a, char **b)
{
	static int i;
	if (total == 3)
	{
		if (max(ft_atoi(a[0]), ft_atoi(a[1])) == ft_atoi(a[0]) && max(ft_atoi
						(a[2]), ft_atoi(a[1])) == ft_atoi(a[1]))
		{
			sa(a);
			the_writer(a, b);
			a = rra(a);
			the_writer(a, b);
		}
		else if (max(ft_atoi(a[0]), ft_atoi(a[1])) == ft_atoi(a[0]) && max(ft_atoi
					(a[2]), ft_atoi(a[1])) == ft_atoi(a[2]) && max(ft_atoi
					(a[0]), ft_atoi(a[2])) == ft_atoi(a[2]) )
		{
			sa(a);
			the_writer(a, b);
		}
		else if (max(ft_atoi(a[0]), ft_atoi(a[1])) == ft_atoi(a[0]) && max(ft_atoi
					(a[2]), ft_atoi(a[1])) == ft_atoi(a[2]))
		{
			a = ra(a);
		}
		else if (max(ft_atoi(a[0]), ft_atoi(a[1])) == ft_atoi(a[1]) && max(ft_atoi
					(a[2]), ft_atoi(a[1])) == ft_atoi(a[1]) && max(ft_atoi
					(a[0]), ft_atoi(a[2])) == ft_atoi(a[2]))
		{
			pb(&a, &b);
			the_writer(a, b);
			sa(a);
			the_writer(a, b);
			pa(&a, &b);
			the_writer(a, b);
		}
	else
	{
		a = rra(a);
	}		
	}
	return (a);
}
void push_swap(char **a, char **b)
{
	if (done(a) == 1)
	{
		return ;
	}
	unsigned int j;
	unsigned int m;
	unsigned int M;
	int n = 0;
	int total = ft_strcount(a);
	the_writer(a, b);
	if (total == 2)
	{
		if (!(done(a) == 1))
		{
			sa(a);
			the_writer(a, b);
		}
		return;
	}
	if (total == 3)
	{
		a = case_of_3(total, a, b);
		b = NULL;
		return ;
	}
	if (total < 100)
	{
	while (!(done(a) == 1))
	{
		total = ft_strcount(a);
		j = snuffer_min(a);
		if (total == 3)
		{
			a = case_of_3(total, a, b);
			break ;
		}
		if (j == 0)
		{
			pb(&a, &b);
			the_writer(a, b);
		}
		else if (j == 1)
		{
				sa(a);
			the_writer(a, b);
				pb(&a, &b);
			the_writer(a, b);
		}
		else if (j < (total / 2) - 1)
		{
			while (n < j)
			{
				if (done(a) == 1)
					break ;
				a = ra(a);
				j--;
				the_writer(a, b);
			}
		}
		else
		{
			while (total > j)
			{
				if (done(a) == 1)
					break;
				a = rra(a);
				j++;
				the_writer(a,b);
			}
		}
		
	}
	n = 0;
	j = ft_strcount(b);
	while (n < j)
	{
		pa(&a,&b);
	the_writer(a,b);
		n++;
	}
	}
	else 
	{
		while (ft_strcount(a))
		{
			total = ft_strcount(a);
			m = snuffer_min(a);
			M = snuffer_max(a);
			if (m == 0)
			{
				pb(&a, &b);
				the_writer(a, b);	
			}
			else if (M == 0)
			{
				pb(&a, &b);
				the_writer(a, b);
			if (ft_strcount(b) > 1)
				{
				//	exit(0);
					b = rb(b);
					the_writer(a, b);
				}
			}
			else if (snuffer_min(a) == 1)
			{
				sa(a);
				the_writer(a, b);
				pb(&a, &b);
				the_writer(a, b);
			}
			else if (snuffer_max(a) == 1)
			{
				sa(a);
				the_writer(a, b);
				pb(&a, &b);
				the_writer(a, b);
				if (ft_strcount(b) > 1)
				{
				//	exit(0);
					b = rb(b);
					the_writer(a, b);
				}
			}
			else if (((total - M) <= m && M > total / 2))
			{
				while (M <= total)
				{
					if (snuffer_max(a) == 0)
						break ;
					a = rra(a);
					M++;
					the_writer(a,b);
				}
			}			
			else if ((total - m) < M  && m > total / 2)
			{
				while (m <= total)
				{
					if (snuffer_min(a) == 0)
						break ;
					a = rra(a);
					m++;
					the_writer(a,b);
				}
			}
			else if (M < m && M <= total / 2)
			{
				while (M > 0)
				{
					if (snuffer_max(a) == 0)
						 break ;
					a = ra(a);
				the_writer(a, b);
					M--;
				}
				pb(&a, &b);
				the_writer(a, b);
				if (ft_strcount(b) > 1)
				{
				//	exit(0);
					b = rb(b);
					the_writer(a, b);
				}
			}
			else if (m < M && m <= total / 2)
			{
				while (m > 0)
				{
					if (snuffer_min(a) == 0)
						 break ;
					a = ra(a);
				the_writer(a, b);
					m--;
				}
				pb(&a, &b);
				the_writer(a, b);
			}
			if (ft_strcount(a) == 1)
				pb(&a, &b);

		}
		while (!(done_b(b) == 1))
		{
			b = rrb(b);
			the_writer(a, b);
		}
		n = ft_strcount(b);
		while (n--)
		{
			pa(&a, &b);
			the_writer(a,b);
		}
	}
}
