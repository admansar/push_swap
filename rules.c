/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2022/12/12 20:23:31 by admansar         ###   ########.fr       */
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
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int ft_strcount(char **c)
{
	int i = 0;
	while (c[i])
		i++;
	return (i);
}
char **first_to_first(char **a, char **b)
{
	int i = 0;
	int j = 0;
	char **re;
	
	while (b[i])
		i++;
	re  = ft_calloc(sizeof(char *)  ,i + 2);
	while (j < i)
	{
		re[j + 1] = b[j];
		j++;
	}
	re[0] = a[0];
	re[j + 1] = 0;
	return (re);
}
//to ecrase the first caractere in the string
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
		re[i] = c[i + 1];
		i++;
	}
	re[i] = c[i + 1];
	//free(c);
	return (re);
}
//switch the first two in a, no need to affect
char **sa(char **c)
{
	c = switch_1_2(c);
	ft_printf("sa\n");
	return (c);
}
//switch the first two in b, no need to affect
char **sb(char **c)
{
	c = switch_1_2(c);
	ft_printf("sb\n");
	return (c);
}
//switch a and b in the same time
// please fix me 
void ss(char ***c1, char ***c2)
{
	*c1 = switch_1_2(*c1);
	*c2 = switch_1_2(*c2);
	ft_printf("ss\n");
}
// prent le premier valeur dans le premier tableau et l'affecte au dexieme tableau
// atention !!! passage par adress
void pb(char ***a, char ***b)
{
	*b = first_to_first(*a, *b);
	*a = ecrase_avant(*a);
	ft_printf("pb\n");
}
void pa(char ***b, char ***a)
{
	*b = first_to_first(*a, *b);
	*a = ecrase_avant(*a);
	ft_printf("pa\n");
}
//rotate first to last 
//you should affect
char **ra(char **a)
{
	int i = 0;
	char **re;
	re = calloc (ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		re [i] = a[i];
		i++;
	}
	re[i] = a[0];
	re = ecrase_avant(re);
	ft_printf("ra\n");
	return (re);
}
char **rb(char **a)
{
	int i = 0;
	char **re;
	re = calloc (ft_strcount(a) + 2, sizeof(char *));
	while (a[i])
	{
		re [i] = a[i];
		i++;
	}
	re[i] = a[0];
	re = ecrase_avant(re);
	ft_printf("rb\n");
	return (re);
}
//write like exampels in the subject
void the_writer(char **a, char **b)
{
	int i;
	i = 0;
	int k;
	k = max (ft_strcount (a), ft_strcount(b));
	while (i < k)
	{
		if (a[i] != NULL && b[i] != NULL)
		ft_printf("%s\t%s\n",a[i],b[i]);
		else if ((a[i] == NULL || !a[i]) && b[i] != NULL)
		ft_printf(" \t%s\n",b[i]);
		else if (a[i] != NULL && (b[i] == NULL || !b[i]))
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
	int j;
	a = ft_calloc(ac , sizeof(char *));
	b = ft_calloc(ac , sizeof(char *));
	i = 0;
	j = 0;
	while (av[i])
		i++;
	while (av[j])
	{
		a[i - j - 1] = av[j];
		j++; 
	}
	a[j - 1] = 0;
	ft_error(a);
	//sa(a);
	//pb(&a,&b);
	//pa(&a,&b);
	pb(&a, &b);
	the_writer(a,b);
	pb(&a, &b);
	the_writer(a,b);
	return (0);
}
