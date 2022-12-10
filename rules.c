/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2022/12/10 15:02:25 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/ft_printf.h"
# include "libft/libft.h"
// to check if the input is a number (returns 1 in this case)
int check_if_number(char *c)
{
	int i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
// to check that everything there is a digit number 
void ft_error(char **c)
{
	int i = 0;
	while (c[i])
	{
		if (check_if_number(c[i]) == 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
			i++;
	}
}
// to switch the first with the second
char **switch_1_2(char **c)
{
	char *tmp;
	int i = 0;
	while (c[0][i])
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	i = 0;
	while (c[0][i])
	{
		tmp[i] = c[0][i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (c[1][i])
	{
		c[0][i] = c[1][i];
		i++;
	}
	c[0][i] = '\0';
	i = 0;
	while (tmp[i])
	{
		c[1][i] = tmp[i];
		i++;
	}
	c[1][i] = '\0';
	return (c);
}
char **ecrase_avant(char **c)
{
	int i = 0;
	char **re;
	while (c[i])
		i++;
	re = malloc (sizeof(char *) * i);
	i = 0;
	while (c[i + 1])
	{
		// hna kin probleme
		re[i] = c[i + 1];
		i++;
	}
	re[i] = NULL;
	return (re);
}
//switch the first two in a
char **sa(char **c)
{
	c = switch_1_2(c);
	ft_printf("sa\n");
	return (c);
}
//switch the first two in b
char **sb(char **c)
{
	c = switch_1_2(c);
	ft_printf("sb\n");
	return (c);
}
//switch a and b in the same time
void **ss(char **c1, char **c2)
{
	c1 = switch_1_2(c1);
	c2 = switch_1_2(c2);
	ft_printf("ss\n");
	return 0;
}
//write like exampels in the subject
void the_writer(char **a, char **b)
{
	int i;
	i = 0;

	while (a[i] || b[i])
	{
		if (a[i] != NULL && b[i] != NULL)
		ft_printf("%s\t%s\n",a[i],b[i]);
		else if (a[i] == NULL && b[i] != NULL)
		ft_printf(" \t%s\n",b[i]);
		else if (a[i] != NULL && b[i] == NULL)
		ft_printf("%s\t \n",a[i]);

		i++;
	}
	ft_printf("---\t---\n a \t b \n");
}

int main(int ac, char **av)
{
	char **a;
	char **b;
	int i;
	a = ft_calloc(ac , sizeof(char *));
	b = ft_calloc(ac , sizeof(char *));
	i = 0;
	while (av[i])
	{
		a[i] = av[i + 1];
		i++;
	}
	i = 0;
	ft_error(a);
	//sa(a);
	ecrase_avant(a);
	the_writer(a,b);
	return (0);
}
