/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:21:14 by admansar          #+#    #+#             */
/*   Updated: 2023/03/31 16:05:39 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long	counter_space(char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ')
		i++;
	return (i);
}

void	init_errors(int ac, char **av)
{
	int	i;

	i = ac;
	while (i--)
	{
		if (!ft_strlen(av[i]))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
	}
	while (++i < ac)
	{
		if (ft_strlen(av[i]) == counter_space(av[i]))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
	}
}

void	freeing_machine(char **a, char **b, int i)
{
	i = 0;
	if (ft_strcount(a) && !ft_strcount(b))
	{
		while (a[i])
			free(a[i++]);
		free(a);
		free(b);
	}
	else if (ft_strcount(b) && !ft_strcount(a))
	{
		while (b[i])
			free(b[i++]);
		free(b);
		free(a);
	}
	else if (ft_strcount(a) && ft_strcount(b))
	{
		while (a[i])
			free(a[i++]);
		free(a);
		i = 0;
		while (b[i])
			free(b[i++]);
		free(b);
	}
}

int	main(int ac, char **av)
{
	char	**a;
	char	**b;

	if (ac == 1)
		exit(0);
	init_errors(ac, av);
	av = split_args(av);
	a = words(av);
	ft_error(a);
	b = ft_calloc(1, sizeof(char *));
	checker(a, b);
	return (0);
}
