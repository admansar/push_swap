/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:54 by admansar          #+#    #+#             */
/*   Updated: 2022/12/15 17:44:21 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	char	**a;
	char	**b;

	b = ft_calloc(ac, sizeof(char *));
	av = split_args(av);
//	a = reverse_words(av);
	a = words(av);
	ft_error(a);
	push_swap(a,b);
	return (0);
}
