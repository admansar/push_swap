/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:33:30 by admansar          #+#    #+#             */
/*   Updated: 2023/03/29 22:00:52 by admansar         ###   ########.fr       */
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
	int		i;
	char	*re;

	re = ft_calloc(sizeof(char), ft_strlen(c));
	i = 0;
	while (c[i + 1])
	{
		re[i] = c[i + 1];
		i++;
	}
	re[i] = '\0';
	ft_strlcpy(c, re, ft_strlen(re) + 1);
	free(re);
	return (c);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*re;

	re = ft_strjoin(s1, s2);
	free(s2);
	return (re);
}

char	*n9i(char *c)
{
	int		i;
	char	*tmp;
	int		negative;

	i = 0;
	negative = 0;
	if (c[i] == '+' && ft_strlen(c) > 1)
		hla9(c);
	else if (c[i] == '-' && ft_strlen(c) > 1)
	{
		hla9(c);
		negative = 1;
	}
	while (c[i] == '0' && c[i + 1])
		hla9(c);
	if (negative == 1 && ft_strncmp(c, "0", 2))
	{
		tmp = ft_strjoin("-", c);
		ft_strlcpy(c, tmp, ft_strlen(tmp) + 1);
		free(tmp);
	}
	return (c);
}

// to check that you have not repeat a world
int	detective(char **c)
{
	int		i;
	int		j;
	char	*holder;

	i = 0;
	j = 0;
	while (c[i])
	{
		holder = n9i(c[i]);
		ft_strlcpy(c[i], holder, ft_strlen(holder) + 1);
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
