/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:53:33 by admansar          #+#    #+#             */
/*   Updated: 2023/03/30 23:48:02 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>

char			**switch_1_2(char **c);
int				max(int a, int b);
int				ft_strcount(char **c);
char			**first_to_first(char **a, char **b);
char			**ecrase_avant(char **c);
char			**sa(char **c);
char			**sb(char **c);
void			ss(char ***c1, char ***c2);
void			pb(char ***a, char ***b);
void			pa(char ***a, char ***b);
char			**rftl(char **a);
char			**ra(char **a);
char			**rb(char **b);
void			rr(char ***a, char ***b);
char			**rra(char **a);
char			**rrb(char **b);
void			rrr(char ***a, char ***b);
void			the_writer(char **a, char **b);
char			**reverse_words(char **av);
char			**reverse_rotate(char **a);
char			**words(char **av);
char			**my_spliter(char *s, int i, int j, int k);
char			**ft_joiner(char **s1, char **s2);
char			**split_args(char **v);
char			*protecter(char *str, int i);
char			*cutter(char *s);
int				space_counter(char *s);
void			push_swap(char **a, char **b);
char			**sorted_clone(char **c);
int				next_num(char **a, int xhal);
char			**needed_clone(char **a, int ke);
int				done(char **a);
int				done_b(char **b);
int				min(char **a);
int				max_num(char **b);
unsigned int	snuffer_max(char **a);
unsigned int	snuffer_min(char **a);
char			**case_of_3(char ***a, char **b);
int				number_still_inside(char **a, int ke);
void			push_back(char **a, char **b, char **sorted);
char			**norm_ra(char **a, int n, int j);
char			**norm_rra(char **a, int total, int j);
void			simple_sort(char **a, char **b, int j, int n);
void			case_(char **a, char **b, int c);
void			free_exit(char **a, char **b, int i1, int i2);
void			push_swap(char **a, char **b);
char			*n9i(char *c);
char			*hla9(char *c);
int				check_if_number(char *c, int i, int n, int j);
int				detective(char **c);
void			ft_error(char **c);
int				yup(int j, int n, int i, char *c);
char			**the_clone(char **c);
char			**ft_str_pro_cpy(char **re, char **a);
void			error_(char **a);
char			**norm_(char **a, int n, int total, int j);
char			**ft_str_2_cpy(char **re, char **a);
void			free_ranger(char **a, char **b, char **sorted);
void			pa_bonus(char ***b, char ***a);
char			**sa_bonus(char **c);
char			**sb_bonus(char **c);
void			ss_bonus(char ***c1, char ***c2);
void			pb_bonus(char ***a, char ***b);
void			pa_bonus(char ***a, char ***b);
char			**rra_bonus(char **a);
void			rr_bonus(char ***a, char ***b);
char			**rb_bonus(char **a);
char			**ra_bonus(char **a);
void			rrr_bonus(char ***a, char ***b);
char			**rrb_bonus(char **b);
void			checker(char **a, char **b);
void			cases(char ***a, char ***b, char **r, int i);
void			continue_1(char ***a, char ***b, char **r, int i);
void			continue_2(char ***a, char ***b, char **r, int i);
void			the_end(char ***a, char ***b, char **r, int i);
void			nothing(void);
void			freeing_machine(char **a, char **b, int i);

#endif
