/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:04:02 by admansar          #+#    #+#             */
/*   Updated: 2022/12/24 15:56:46 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_joiner(char **s1, char **s2)
{
	char	**re;
	int		j;
	int		i;

	j = 0;
	i = 0;
	re = ft_calloc(ft_strcount(s1) + ft_strcount(s2) + 1, sizeof(char *));
	while (i < ft_strcount(s1))
	{
		re[i] = s1[i];
		i++;
	}
	while (j < ft_strcount(s2))
	{
		re[i + j] = s2[j];
		j++;
	}
	re[i + j] = s2[j];
	free(s1);
	return (re);
}

char	**split_args(char **av)
{
	char	**c;
	char	**c2;
	int		i;

	i = 0;
	c = malloc(1);
	while (av[i])
	{
		c2 = my_spliter(av[i], 0, 0, 0);
		c = ft_joiner(c, c2);
		i++;
		free(c2);
	}
	return (c);
}
