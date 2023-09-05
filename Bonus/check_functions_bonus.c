/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:28 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/07 22:05:39 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	args_check(char *str, t_stacks *p, char *s)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		ft_putstr("Error\n");
		free(s);
		exit(1);
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			break ;
		i++;
		if (!str[i])
		{
			ft_putstr("Error\n");
			free(s);
			exit(1);
		}
	}
}

void	same_num_check(t_stacks *p, int x, char *str)
{
	int	i;

	i = x - 1;
	while (x > 0)
	{
		while (i >= 0)
		{
			if (p->stacka[i] == p->stacka[x])
			{
				free(str);
				error(p);
			}
			i--;
		}
		x--;
		i = x - 1;
	}
}

int	*check_fct(char *str, t_stacks *p)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0'
					&& str[i + 1] <= '9')))
		{
			if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			{
				free(str);
				error(p);
			}
		}
		if ((str[i] == '-' || str[i] == '+') && i != 0 && str[i - 1] != ' ')
		{
			free(str);
			error(p);
		}
		i++;
	}
	return (0);
}

int	if_arranged(t_stacks *p)
{
	int	i;

	i = 0;
	while (i < p->size)
	{
		if (p->stacka[i] > p->stacka[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	error(t_stacks *p)
{
	ft_putstr("Error\n");
	free(p->stacka);
	free(p->stackb);
	exit(1);
}
