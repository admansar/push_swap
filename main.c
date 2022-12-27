/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:54 by admansar          #+#    #+#             */
/*   Updated: 2022/12/27 19:09:08 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**a;
	char	**b;

	if (ac == 1)
		exit(1);
	b = ft_calloc(1, sizeof(char *));
	av = split_args(av);
	a = words(av);
	ft_error(a);
	push_swap(a, b);
	free(a);
	free(b);
	return (0);
}
