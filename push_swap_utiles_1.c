/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:00:02 by admansar          #+#    #+#             */
/*   Updated: 2023/01/01 20:18:21 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**swaper(char **a, char *tmp, int i)
{
	while (a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
		{
			tmp = malloc(sizeof(char) * (ft_strlen(a[i]) + 1));
			ft_strlcpy(tmp, a[i], ft_strlen(a[i]) + 1);
			ft_strlcpy(a[i], a[i - 1], ft_strlen(a[i - 1]) + 1);
			ft_strlcpy(a[i - 1], tmp, ft_strlen(tmp) + 1);
			free(tmp);
			i = 0;
		}
		i++;
	}
	return (a);
}

char	**sorted_clone(char **c)
{
	char	**a;
	int		i;

	i = 0;
	a = ft_calloc(sizeof(char *), (ft_strcount(c) + 1));
	while (c[i])
	{
		a[i] = ft_calloc(ft_strlen(c[i]) + 1, sizeof(char));
		ft_strlcpy(a[i], c[i], ft_strlen(c[i]) + 1);
		i++;
	}
	i = 1;
	a = swaper(a, NULL, i);
	return (a);
}

char	**needed_clone(char **a, int ke)
{
	int		i;
	char	**re;
	int		h;

	i = 0;
	re = ft_calloc(sizeof(char *), (ke + 2));
	while (i <= ke)
	{
		h = ft_strlen(a[i]) + 1;
		re[i] = ft_calloc(h, sizeof(char));
		ft_strlcpy(re[i], a[i], h);
		i++;
	}
	return (re);
}

//to make sure that everything is done (return 1 if everything cool)
int	done(char **a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i - 1]) > ft_atoi(a[i]))
			return (0);
		i++;
	}
	return (1);
}

int	done_b(char **b)
{
	int	i;

	i = 1;
	while (b[i])
	{
		if (ft_atoi(b[i - 1]) < ft_atoi(b[i]))
			return (0);
		i++;
	}
	return (1);
}
