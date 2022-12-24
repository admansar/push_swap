/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:05:17 by admansar          #+#    #+#             */
/*   Updated: 2022/12/24 16:04:47 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to check if its a number or not
int	sensor(char **av)
{
	int		i;
	int		j;
	char	*dual;

	i = 0;
	j = 0;
	while (j < ft_strcount(av))
	{
		dual = ft_itoa(ft_atoi(av[j]));
		while (av[j][i])
		{
			if (dual[i] != av[j][i])
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	free(dual);
	return (1);
}

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
	if (detective(c) == 1 || sensor(c) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
