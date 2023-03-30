/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 02:01:56 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate (sense of derive cos)
// affectation
char	**ra_bonus(char **a)
{
	char	**re;

	re = ft_str_pro_cpy(NULL, rftl(a));
	return (re);
}

char	**rb_bonus(char **a)
{
	char	**re;

	re = ft_str_pro_cpy(NULL, rftl(a));
	return (re);
}

// ra && rb in the same time
// paasage par adress
void	rr_bonus(char ***a, char ***b)
{
	*a = rftl(*a);
	*b = rftl(*b);
}

//reverse rotate a (integral of cos)
//you should affect
char	**rra_bonus(char **a)
{
	char	**re;

	re = ft_str_pro_cpy(NULL, reverse_rotate(a));
	return (re);
}
