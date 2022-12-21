/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2022/12/21 16:50:57 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
