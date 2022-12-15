/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:57:08 by admansar          #+#    #+#             */
/*   Updated: 2022/12/13 18:01:00 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//write like exampels in the subject
void	the_writer(char **a, char **b)
{
	int	i;
	int	k;

	i = 0;
	k = max(ft_strcount(a), ft_strcount(b));
	while (i < k)
	{
		if (a[i] != NULL && b[i] != NULL)
			ft_printf("%s\t%s\n", a[i], b[i]);
		else if ((a[i] == NULL || !a[i]) && b[i] != NULL)
			ft_printf(" \t%s\n", b[i]);
		else if (a[i] != NULL && (b[i] == NULL || !b[i]))
			ft_printf("%s\t \n", a[i]);
		i++;
	}
	ft_printf("---\t---\n a \t b \n");
}
//reverse teh words and delete the first one (./a.out in my case)
char	**reverse_words(char **av)
{
	int		j;
	int		i;
	char	**a;

	j = 0;
	i = ft_strcount(av);
	a = malloc((i + 1) * sizeof(char *));
	while (av[j])
	{
		a[i - j - 1] = av[j];
		j++;
	}
	a[j - 1] = 0;
	return (a);
}
