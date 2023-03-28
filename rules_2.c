/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2023/03/26 23:19:47 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate (sense of derive cos)
// affectation
char	**ra(char **a)
{
	char	**re;

	re = ft_str_pro_cpy(NULL, rftl(a));
	ft_printf("ra\n");
	return (re);
}

char	**rb(char **a)
{
	int		i;
	char	**re;

	i = 0;
	re = ft_str_pro_cpy(NULL, rftl(a));
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
	int		i;
	char	**re;

	i = 0;
	re = ft_str_pro_cpy(NULL, reverse_rotate(a));
	ft_printf("rra\n");
	return (re);
}
