/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:12:58 by admansar          #+#    #+#             */
/*   Updated: 2022/12/10 10:44:10 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*get_save(char *save);
char	*get_the_line(char *save);
char	*my_join(char *s1, char *s2);
char	*get_read(int fd, char *save);
char	*get_next_line(int fd);
int		the_found(char *str, char c);
#endif
