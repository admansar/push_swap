/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:05:17 by admansar          #+#    #+#             */
/*   Updated: 2022/12/21 16:25:58 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	yup(int j, int n, int i, char *c)
{
	while (j > 0)
	{
		j = j / 10;
		n++;
	}
	while (c[i++] == '0')
		n++;
	return (n);
}

// to check if the input is a number (returns 0 in this case)
int	check_if_number(char *c, int i, int n, int j)
{
	if (j > 0)
	{
		if (c[0] == '+')
		n = yup(j, ++n, ++i, c);
		else
			n = yup(j, n, i, c);
		if ((int)ft_strlen(c) == n)
			return (1);
	}
	else if (j < 0)
	{
		n = yup(-j, ++n, ++i, c);
		if ((int)ft_strlen(c) == n)
			return (1);
	}
	else if (j == 0)
	{
		if (c[i] == '+' || c[i] == '-')
			i++;
		while (c[i] == '0')
			i++;
		if ((int)ft_strlen(c) == i)
			return (1);
	}
	return (0);
}

// to check that you have not repeat a world
int	detective(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i])
	{
		j = i + 1;
		while (c[j])
		{
			if (ft_atoi(c[i]) == ft_atoi(c[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(char **c)
{
	int	i;
	int	k;
	int	p;
	int	ne;

	i = 0;
	k = 0;
	p = 0;
	while (c[i])
	{
		ne = ft_atoi(c[i]);
		if (check_if_number(c[i], k, p, ne) == 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
			i++;
	}
	if (detective(c) == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
