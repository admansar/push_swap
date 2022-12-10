/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admansar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:18:24 by admansar          #+#    #+#             */
/*   Updated: 2022/12/10 12:43:41 by admansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/ft_printf.h"
# include "libft/libft.h"

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
char **sa(char **c)
{
	c = switch_1_2(c);
	ft_printf("sa\n");
	return (c);
}
char **sb(char **c)
{
	c = switch_1_2(c);
	ft_printf("sb\n");
	return (c);
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
	sa(a);
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
	return (0);
}
