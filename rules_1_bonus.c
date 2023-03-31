/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:39:30 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 02:19:35 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//switch the first two in a, no need to affect
// seg fault means that you wanted to
// swap one element thats a useles task !!
char	**sa_bonus(char **c)
{
	switch_1_2(c);
	return (c);
}

//switch the first two in b, no need to affect
// seg fault means that you wanted to
// swap one element thats a useles task !!
char	**sb_bonus(char **c)
{
	switch_1_2(c);
	return (c);
}

//switch a and b in the same time
// seg fautls means that you wanted to
// switch one element thats a usels task !!
void	ss_bonus(char ***c1, char ***c2)
{
	*c1 = switch_1_2(*c1);
	*c2 = switch_1_2(*c2);
}

// prend le premier valeur dans le premier tableau
// et l'affecte au deuxieme tableau
// atention !!! passage par adress
void	pb_bonus(char ***a, char ***b)
{
	*b = ft_str_pro_cpy(NULL, first_to_first(*a, *b));
	*a = ft_str_pro_cpy(NULL, ecrase_avant(*a));
}

void	pa_bonus(char ***b, char ***a)
{
	*b = ft_str_pro_cpy(NULL, first_to_first(*a, *b));
	*a = ft_str_pro_cpy(NULL, ecrase_avant(*a));
}
