/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:30:14 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 23:46:35 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_end(char ***a, char ***b, char **r, int i)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	free((*r));
	freeing_machine(*a, *b, i);
	exit(1);
}

void	continue_2(char ***a, char ***b, char **r, int i)
{
	if (!ft_strncmp((*r), "rrb", 3) && ft_strlen((*r)) == 4
		&& ft_strcount(*b) <= 0)
		nothing();
	else if (!ft_strncmp((*r), "rrb", 3) && ft_strlen((*r)) == 4)
		*b = rrb_bonus(*b);
	else if (!ft_strncmp((*r), "rr", 2) && (ft_strcount(*b) <= 1)
		&& ft_strlen((*r)) == 3)
		*a = ra_bonus(*a);
	else if (!ft_strncmp((*r), "rr", 2) && (ft_strcount(*a) <= 1)
		&& ft_strlen((*r)) == 3)
		*b = rb_bonus(*b);
	else if (!ft_strncmp((*r), "rr", 2) && ft_strlen((*r)) == 3)
		rr_bonus(a, b);
	else if (!ft_strncmp((*r), "rrr", 3) && (ft_strcount(*b) <= 1)
		&& ft_strlen((*r)) == 4)
		*a = rra_bonus(*a);
	else if (!ft_strncmp((*r), "rrr", 3) && (ft_strcount(*a) <= 1)
		&& ft_strlen((*r)) == 4)
		*b = rrb_bonus(*b);
	else if (!ft_strncmp((*r), "rrr", 3) && ft_strlen((*r)) == 4)
		rrr_bonus(a, b);
	else
		the_end(a, b, r, i);
}

void	continue_1(char ***a, char ***b, char **r, int i)
{
	if (!ft_strncmp((*r), "ss", 2) && (ft_strcount(*a) <= 1)
		&& ft_strlen((*r)) == 3)
		sb_bonus(*b);
	else if (!ft_strncmp((*r), "ss", 2) && ft_strlen((*r)) == 3)
		ss_bonus(a, b);
	else if (!ft_strncmp((*r), "rb", 2) && ft_strlen((*r)) == 3
		&& ft_strcount(*b) <= 0)
		nothing();
	else if (!ft_strncmp((*r), "rb", 2) && ft_strlen((*r)) == 3)
		*b = rb_bonus(*b);
	else if (!ft_strncmp((*r), "ra", 2) && ft_strlen((*r)) == 3
		&& ft_strcount(*a) <= 0)
		nothing();
	else if (!ft_strncmp((*r), "ra", 2) && ft_strlen((*r)) == 3)
		*a = ra_bonus(*a);
	else if (!ft_strncmp((*r), "rra", 3) && ft_strlen((*r)) == 4
		&& ft_strcount(*a) <= 0)
		nothing();
	else if (!ft_strncmp((*r), "rra", 3) && ft_strlen((*r)) == 4
		&& ft_strcount(*a) <= 0)
		nothing();
	else if (!ft_strncmp((*r), "rra", 3) && ft_strlen((*r)) == 4)
		*a = rra_bonus(*a);
	else
		continue_2(a, b, r, i);
}

void	cases(char ***a, char ***b, char **r, int i)
{
	if (!ft_strncmp((*r), "sa", 2) && ft_strcount(*a) <= 1
		&& ft_strlen((*r)) == 3)
		nothing();
	else if (!ft_strncmp((*r), "sa", 2) && ft_strlen((*r)) == 3)
		sa_bonus(*a);
	else if (!ft_strncmp((*r), "sb", 2) && ft_strcount(*b) <= 1
		&& ft_strlen((*r)) == 3)
		nothing();
	else if (!ft_strncmp((*r), "sb", 2) && ft_strlen((*r)) == 3)
		sb_bonus(*b);
	else if (!ft_strncmp((*r), "pa", 2) && ft_strcount(*b) <= 0
		&& ft_strlen((*r)) == 3)
		nothing();
	else if (!ft_strncmp((*r), "pa", 2) && ft_strlen((*r)) == 3)
		pa_bonus(a, b);
	else if (!ft_strncmp((*r), "pb", 2) && ft_strcount(*a) <= 0
		&& ft_strlen((*r)) == 3)
		nothing();
	else if (!ft_strncmp((*r), "pb", 2) && ft_strlen((*r)) == 3)
		pb_bonus(a, b);
	else if (!ft_strncmp((*r), "ss", 2) && (ft_strcount(*b) <= 1)
		&& ft_strlen((*r)) == 3)
		sa_bonus(*a);
	else
		continue_1(a, b, r, i);
}

void	checker(char **a, char **b)
{
	char	*r;
	int		i;

	i = 0;
	r = get_next_line(0);
	while (r)
	{
		cases(&a, &b, &r, i);
		free(r);
		r = get_next_line(0);
	}
	if (!ft_strcount(a))
		ft_printf("KO\n");
	else if (done(a) && !ft_strcount(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freeing_machine(a, b, i);
}
