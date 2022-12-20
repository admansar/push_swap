/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/20 13:23:33 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char  **sorted_clone(char **c)
{
	char **a;
	int i = 0;
	char *tmp;
	a = malloc (sizeof(char *) * (ft_strcount(c) + 1));
	while (c[i])
	{
		a[i] = c[i];
		i++;
	}
	a[i] = c[i];	
	i = 1;
	while(a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
		{
			tmp = malloc (sizeof(char) * (ft_strlen (a[i]) + 1));
			tmp = a[i];
			a[i] = a[i - 1];
			a[i - 1] = tmp;
			i = 1;
		}
		i++;
	}
	return (a);
}

int next_num(char **a, int xhal)
{
	int i = 0;
	int j = ft_strcount(a) / xhal;
	static int b;

	b +=j;
	if (b > ft_strcount(a))
		b = ft_strcount(a) - 1;
	return (ft_atoi(a[b]));
}
char **needed_clone(char **a, int ke)
{
	int i = 0;
	char **re;

	re = malloc(sizeof (char *) * (ke + 1));
	while (i <= ke)
	{
		re[i] = a[i];
		i++;
	}
	re[i] = NULL;
	return (re);
}
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
			// the_writer(a, b);
			a = rra(a);
			// the_writer(a, b);
		}
		else if (max(ft_atoi(a[0]), ft_atoi(a[1])) == ft_atoi(a[0]) && max(ft_atoi
					(a[2]), ft_atoi(a[1])) == ft_atoi(a[2]) && max(ft_atoi
					(a[0]), ft_atoi(a[2])) == ft_atoi(a[2]) )
		{
			sa(a);
			// the_writer(a, b);
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
			// the_writer(a, b);
			sa(a);
			// the_writer(a, b);
			pa(&a, &b);
			// the_writer(a, b);
		}
	else
	{
		a = rra(a);
	}		
	}
	return (a);
}
int number_still_inside(char **a, int ke)
{
	int i = 0;
	while (a[i])
	{
		if (ft_atoi(a[i]) < ke)
			return (1);
		i++;
	}
	return (0);
}

void case_500(char **a, char **b)
{
	int i = 0;
	int n;
	char **alpha;
	int ke = 0;
	while (ke != ft_strcount(a) - 1 && ft_strcount(a))
	{
		ke = next_num(sorted_clone(a), 50);
		while (number_still_inside(a, ke))
		{
			

			if (ft_atoi(a[i]) <= ke)
			{
				pb(&a,&b);
				// the_writer(a,b);
			}
			else
			{
				a = ra(a);
				// the_writer(a, b);
			}
		}
	}
	alpha = 0;
	while (ft_strcount(b))
	{
		if (snuffer_max(b) == 0)
		{
			pa(&a, &b);
			// the_writer(a, b);
		}
		else 
		{
			if (snuffer_max(b) < (ft_strcount(b) /2) + 1)
			{
				while (snuffer_max(b))
				{
					b = rb(b);
					// the_writer(a, b);
				}
			}
			else 
			{
				while (snuffer_max(b))
				{
					b = rrb(b);
					// the_writer(a, b);
				}
			}
		}
	}
}

void case_100(char **a, char **b)
{
	int i = 0;
	int n;
	char **alpha;
	int ke = 0;
	while (ft_strcount(a))
	{
		ke = next_num(sorted_clone(a), 10);
		while (number_still_inside(a, ke) && ft_strcount(a))
		{
			

			if (ft_atoi(a[i]) <= ke)
			{
				pb(&a,&b);
				// the_writer(a,b);
			}
			else
			{
				a = ra(a);
				// the_writer(a, b);
			}
		}
	}
	int total;
	alpha = 0;
	while (ft_strcount(b))
	{
		if (snuffer_max(b) == 0)
		{
			pa(&a, &b);
			// the_writer(a, b);
		}
		else 
		{
			total = ft_strcount(b);
			if (snuffer_max(b) < (total /2) + 1)
			{
				while (snuffer_max(b))
				{
					b = rb(b);
					// the_writer(a, b);
				}
			}
			else 
			{
				while (snuffer_max(b))
				{
					b = rrb(b);
					// the_writer(a, b);
				}
			}
		}
	}
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
	int ke;
	int n = 0;
	int total = ft_strcount(a);
	// the_writer(a, b);
	if (total == 2)
	{
		if (!(done(a) == 1))
		{
			sa(a);
			// the_writer(a, b);
		}
		return;
	}
	else if (total == 3)
	{
		a = case_of_3(total, a, b);
		b = NULL;
		return ;
	}
	else if (total < 10)
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
				// the_writer(a, b);
			}
			else if (j == 1)
			{
				sa(a);
			// the_writer(a, b);
				pb(&a, &b);
			// the_writer(a, b);
			}
			else if (j < (total / 2) + 1)
			{
				while (n < j)
				{
					if (done(a) == 1)
						break ;
					a = ra(a);
					j--;
					// the_writer(a, b);
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
					// the_writer(a,b);
				}
			}
		}
		n = 0;
		j = ft_strcount(b);
		while (n < j)
		{
			pa(&a,&b);
			// the_writer(a,b);
			n++;
		}
	}
	else if (total <= 100) 
	{
		case_100(a,b);	
	}
	else 
	{
			case_500(a,b);
	}		
}
