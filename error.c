/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:05:17 by admansar          #+#    #+#             */
/*   Updated: 2022/12/13 18:08:24 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to check if the input is a number (returns 1 in this case)
int check_if_number(char *c)
{
	int i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
// to check that you have not repeat a world
int detective(char **c)
{
	int i = 0;
	int j = 0;
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
void ft_error(char **c)
{
	int i = 0;

	while (c[i])
	{
		if (check_if_number(c[i]) == 0)
		{
			ft_printf("Error\n");
			exit (1);
		}
		else
			i++;
	}
	if (detective(c) == 1)
	{
		ft_printf("Error\n");
		exit (1);
	}
}
