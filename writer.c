/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:57:08 by admansar          #+#    #+#             */
/*   Updated: 2022/12/27 00:02:01 by admansar         ###   ########.fr       */
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
		if (i >= ft_strcount(a) && b[i] != NULL)
			ft_printf(" \t%s\n", b[i]);
		else if (a[i] != NULL && i >= ft_strcount(b))
			ft_printf("%s\t \n", a[i]);
		else
			ft_printf("%s\t%s\n", a[i], b[i]);
		i++;
	}
	ft_printf("---\t---\n a \t b \n");
}

//reverse teh words and delete the first one (./a.out in my case)
/*char	**reverse_words(char **av)
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
*/
char	**words(char **av)
{
	int		i;
	char	**a;
	int		h;

	i = 1;
	a = ft_calloc(ft_strcount(av), sizeof(char *));
	while (av[i])
	{
		h = ft_strlen (av[i]) + 1;
		a[i - 1] = malloc(sizeof(char) * h);
		ft_strlcpy (a[i - 1], av[i], h);
		i++;
	}
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (a);
}
