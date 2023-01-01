/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:33:30 by admansar          #+#    #+#             */
/*   Updated: 2022/12/30 01:27:27 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to check if the input is a number (returns 0 in this case)
int	check_if_number(char *c, int i, int n, int j)
{
	if (j == INT_MAX || j == INT_MIN)
		return (1);
	else if (j > 0)
	{
		if (c[0] == '+')
			n = yup(j, ++n, ++i, c);
		else
			n = yup(j, n, i, c);
	}
	else if (j < 0)
	{
		n = yup(-j, ++n, ++i, c);
	}
	else if (j == 0)
	{
		if (c[i] == '+' || c[i] == '-')
			i++;
		while (c[i] == '0')
			i++;
		return (((int)ft_strlen(c) == i));
	}
	return (((int)ft_strlen(c) == n));
}

char	*hla9(char *c)
{
	char	*re;

		re = ft_calloc(sizeof(char), ft_strlen(c));
		ft_strlcpy(re, c + 1, ft_strlen(c));
		free(c);
		return (re);
}

char	*n9i(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' && ft_strlen(c) > 1)
		c = hla9(c);
	if (c[i] == '+' && ft_strlen(c) > 1)
		c = hla9(c);
	while (c[i] == '0' && c[i + 1])
		c = hla9(c);
	return (c);
}

// to check that you have not repeat a world
int	detective(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i])
	{
		n9i(c[i]);
		j = i + 1;
		while (c[j])
		{
			if (ft_atoi(c[i]) == ft_atoi(c[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
