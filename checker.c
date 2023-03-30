/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:21:14 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 02:49:27 by admansar         ###   ########.fr       */
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

void	checker(char **a, char **b)
{
	char *r;

	r = get_next_line(0);
	while (r)
	{
		if (!ft_strncmp(r, "sa", 2) && ft_strcount(a) <= 1 && ft_strlen(r) == 3)
		{}
		else if (!ft_strncmp(r, "sa", 2) && ft_strlen(r) == 3)
			sa_bonus(a);
		else if (!ft_strncmp(r, "sb", 2) && ft_strcount(b) <= 1 && ft_strlen(r) == 3)
		{}
		else if (!ft_strncmp(r, "sb", 2) && ft_strlen(r) == 3)
			sb_bonus(b);
		else if (!ft_strncmp(r, "pa", 2) && ft_strcount(b) <= 0 && ft_strlen(r) == 3)
		{}
		else if (!ft_strncmp(r, "pa", 2) && ft_strlen(r) == 3)
			pa_bonus(&a, &b);
		else if (!ft_strncmp(r, "pb", 2) && ft_strcount(a) <= 0 && ft_strlen(r) == 3)
		{}
		else if (!ft_strncmp(r, "pb", 2) && ft_strlen(r) == 3)
			pb_bonus(&a, &b);
		else if (!ft_strncmp(r, "ss", 2) && (ft_strcount(b) <= 1) && ft_strlen(r) == 3)
			sa_bonus(a);
		else if (!ft_strncmp(r, "ss", 2) && (ft_strcount(a) <= 1) && ft_strlen(r) == 3)
			sb_bonus(b);
		else if (!ft_strncmp(r, "ss", 2) && ft_strlen(r) == 3)
			ss_bonus(&a, &b);
		else 
		{
			write (2, "Error\n", ft_strlen("Error\n"));
			exit (1);
		}
		the_writer(a,b);
		r = get_next_line(0);
	}
	if (done (a) && !ft_strcount(b))
		ft_printf ("OK\n");
	else
		ft_printf ("KO\n");
	(void)b;
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
//	free(a);
//	free(b);
	return (0);
}
