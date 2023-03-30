/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 02:02:50 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reverse rotate b (integral of cos)
//you should affect
char	**rrb_bonus(char **b)
{
	char	**re;

	re = ft_str_pro_cpy(NULL, reverse_rotate(b));
	return (re);
}

// rra && rrb in the same time
// passage par address
void	rrr_bonus(char ***a, char ***b)
{
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
}
