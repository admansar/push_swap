/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:33 by admansar          #+#    #+#             */
/*   Updated: 2022/12/21 16:54:48 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

int		check_if_number(char *c, int i, int n, int j);
int		detective(char **c);
void	ft_error(char **c);
char	**switch_1_2(char **c);
int		max(int a, int b);
int		ft_strcount(char **c);
char	**first_to_first(char **a, char **b);
char	**ecrase_avant(char **c);
char	**sa(char **c);
char	**sb(char **c);
void	ss(char ***c1, char ***c2);
void	pb(char ***a, char ***b);
void	pa(char ***b, char ***a);
char	**rftl(char **a);
char	**ra(char **a);
char	**rb(char **b);
void	rr(char ***a, char ***b);
char	**rra(char **a);
char	**rrb(char **b);
void	rrr(char ***a, char ***b);
void	the_writer(char **a, char **b);
char	**reverse_words(char **av);
char	**reverse_rotate(char **a);
char	**words(char **av);
char	**my_spliter(char *s, int i, int j, int k);
char	**ft_joiner(char **s1, char **s2);
char	**split_args(char **v);
char	*protecter(char *str, int i);
char	*cutter(char *s);
int		space_counter(char *s);
void	push_swap(char **a, char **b);

#endif
