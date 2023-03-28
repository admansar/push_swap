/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:20:06 by admansar          #+#    #+#             */
/*   Updated: 2023/03/26 22:55:01 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**norm_rra(char **a, int total, int j)
{
	while (total > (int)j++)
	{
		if (done(a) == 1)
			break ;
		a = rra(a);
	}
	return (a);
}

char	**norm_ra(char **a, int n, int j)
{
	char	**re;

	while (n < (int)j--)
	{
		if (done(a) == 1)
			break ;
		a = ra(a);
	}
	re = ft_str_pro_cpy(NULL, a);
	return (re);
}

char	**norm_(char **a, int n, int total, int j)
{
	if ((int)j < (total / 2) + 1)
		a = norm_ra(a, n, j);
	else
		a = norm_rra(a, total, j);
	return (a);
}

int	next_num(char **a, int xhal)
{
	int			j;
	static int	b;

	j = ft_strcount(a) / xhal;
	b += j;
	if (b > ft_strcount(a))
		b = ft_strcount(a) - 1;
	return (ft_atoi(a[b]));
}

char	**ft_str_2_cpy(char **re, char **a)
{
	int	i;
	int	h;

	re = ft_calloc(ft_strcount(a) + 1, sizeof(char *));
	i = 0;
	while (a[i])
	{
		h = ft_strlen(a[i]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], a[i], h);
		i++;
	}
	return (re);
}
