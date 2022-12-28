/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:39:30 by admansar          #+#    #+#             */
/*   Updated: 2022/12/28 17:48:11 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//switch the first two in a, no need to affect
// seg fault means that you wanted to 
// swap one element thats a useles task !!
char	**sa(char **c)
{
	switch_1_2(c);
	ft_printf("sa\n");
	return (c);
}

//switch the first two in b, no need to affect
// seg fault means that you wanted to 
// swap one element thats a useles task !!
char	**sb(char **c)
{
	switch_1_2(c);
	ft_printf("sb\n");
	return (c);
}

//switch a and b in the same time
// seg fautls means that you wanted to 
// switch one element thats a usels task !!
void	ss(char ***c1, char ***c2)
{
	*c1 = switch_1_2(*c1);
	*c2 = switch_1_2(*c2);
	ft_printf("ss\n");
}

// prend le premier valeur dans le premier tableau 
// et l'affecte au deuxieme tableau
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
