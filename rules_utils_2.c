/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2022/12/21 16:52:32 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**rftl(char **a)
{
	int		i;
	char	**re;

	i = 0;
	re = ft_calloc(ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		re[i] = a[i];
		i++;
	}
	re[i] = a[0];
	re = ecrase_avant(re);
	return (re);
}

//rotate in the sense off integral of cos
char	**reverse_rotate(char **a)
{
	char	**re;
	int		i;

	i = 0;
	re = malloc((ft_strcount(a) + 1) * sizeof(char *));
	re[0] = a[ft_strcount(a) - 1];
	while (a[i])
	{
		re[i + 1] = a[i];
		i++;
	}
	re[i] = a[i];
	return (re);
}
