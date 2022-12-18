/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2022/12/17 15:23:48 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//switch the first two in a, no need to affect
// seg fault means that you wanted to swap one element thats a useles task !!
char	**sa(char **c)
{
	c = switch_1_2(c);
	ft_printf("sa\n");
	return (c);
}
//switch the first two in b, no need to affect
// seg fault means that you wanted to swap one element thats a useles task !!
char	**sb(char **c)
{
	c = switch_1_2(c);
	ft_printf("sb\n");
	return (c);
}
//switch a and b in the same time
// seg fautls means that you wanted to switch one element thats a usels task !!
void	ss(char ***c1, char ***c2)
{
	*c1 = switch_1_2(*c1);
	*c2 = switch_1_2(*c2);
	ft_printf("ss\n");
}
// prend le premier valeur dans le premier tableau et l'affecte au deuxieme tableau
// atention !!! passage par adress
void	pb(char ***a, char ***b)
{
	*b = first_to_first(*a, *b);
	*a = ecrase_avant(*a);
	ft_printf("pb\n");
}
void	pa(char ***b, char ***a)
{
	*b = first_to_first(*a, *b);
	*a = ecrase_avant(*a);
	ft_printf("pa\n");
}
// rotate (sense of derive cos)
// affectation
char	**ra(char **a)
{
	char	**re;

	re = rftl(a);
	ft_printf("ra\n");
	return (re);
}
char	**rb(char **a)
{
	char	**re;

	re = rftl(a);
	ft_printf("rb\n");
	return (re);
}
// ra && rb in the same time
// paasage par adress
void	rr(char ***a, char ***b)
{
	*a = rftl(*a);
	*b = rftl(*b);
	ft_printf("rr\n");
}
//reverse rotate a (integral of cos)
//you should affect
char	**rra(char **a)
{
	char	**re;

	re = reverse_rotate(a);
	ft_printf("rra\n");
	return (re);
}

//reverse rotate b (integral of cos)
//you should affect
char	**rrb(char **b)
{
	char	**re;

	re = reverse_rotate(b);
	ft_printf("rrb\n");
	return (re);
}

// rra && rrb in the same time
// passage par address
void	rrr(char ***a, char ***b)
{
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
	ft_printf("rrr\n");
}
