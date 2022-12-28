/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2022/12/28 17:48:52 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**rftl(char **a)
{
	int		h;
	int		i;
	int		j;
	char	**re;

	i = 0;
	j = ft_strcount(a) + 2;
	re = ft_calloc(ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		h = ft_strlen (a[i]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], a[i], h);
//		printf("%d\n", i);
//		printf("%d\n", j);
		i++;
	}
	h = ft_strlen (a[0]) + 1;
	re[i] = ft_calloc(h, sizeof(char));
	ft_strlcpy(re[i], a[0], h);
	re = ecrase_avant(re);
	return (re);
}

//rotate in the sense off integral of cos
char	**reverse_rotate(char **a)
{
	char	**re;
	int		i;
	int		h;
	int		j;

	i = 0;
	j = ft_strcount(a) - 1;
	re = ft_calloc((ft_strcount(a) + 1), sizeof(char *));
	h = ft_strlen(a[ft_strcount(a) - 1]) + 1;
	re[0] = ft_calloc(h, sizeof(char));
	ft_strlcpy(re[0] ,a[ft_strcount(a) - 1], h);
	while (i < j)
	{
		h = ft_strlen(a[i]) + 1;
		re[i + 1] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i + 1] ,a[i], h);
		i++;
	}
	return (re);
}
