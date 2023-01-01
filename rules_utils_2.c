/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:10:26 by admansar          #+#    #+#             */
/*   Updated: 2022/12/31 19:09:22 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
char	**rftl(char **a)
{
	int		h;
	int		i;
	char	**re;

	i = 0;
	re = ft_calloc(ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		h = ft_strlen (a[i]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], a[i], h);
		i++;
	}
	h = ft_strlen (a[0]) + 1;
	re[i] = ft_calloc(h, sizeof(char));
	ft_strlcpy(re[i], a[0], h);
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
//	free(a);
	re = ecrase_avant(re);
	return (re);
}
*/
char	**rftl(char **a)
{
	int		h;
	char 	*tmp;
//	char	**re;
	int		i;

	i = 0;
	tmp = ft_calloc(ft_strlen(a[0]) + 1, sizeof(char));
	ft_strlcpy(tmp, a[0], ft_strlen(a[0]) + 1);
	while (a[i + 1])
	{
		h = ft_strlen(a[i + 1]) + 1;
		ft_strlcpy(a[i], a[i + 1], h);
		i++;
	}
	ft_strlcpy(a[i], tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (a);
}

//rotate in the sense off integral of cos
char	**reverse_rotate(char **a)
{
	char	**re;
	int		i;
	int		h;

	i = 0;
	re = ft_calloc((ft_strcount(a) + 1), sizeof(char *));
	h = ft_strlen(a[ft_strcount(a) - 1]) + 1;
	re[0] = ft_calloc(h, sizeof(char));
	ft_strlcpy(re[0] ,a[ft_strcount(a) - 1], h);
	while (i < ft_strcount(a) - 1)
	{
		h = ft_strlen(a[i]) + 1;
		re[i + 1] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i + 1] ,a[i], h);
		i++;
	}
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (re);
}
