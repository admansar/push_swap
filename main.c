/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:54 by admansar          #+#    #+#             */
/*   Updated: 2023/03/29 22:43:29 by admansar         ###   ########.fr       */
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
	push_swap(a, b);
	free(a);
	free(b);
	return (0);
}
