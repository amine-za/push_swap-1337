/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:49 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/18 23:16:12 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	error(t_stacks *p)
{
	ft_putstr("Error\n");
	free(p->stacka);
	free(p->stackb);
	exit(1);
}

int	count_numbers(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			res++;
			while (str[i] != ' ' && str[i])
				i++;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			i++;
	}
	return (res);
}

char	*check_and_alloc(t_stacks *p, int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(1);
	while (i < ac)
	{
		args_check(av[i], p, str);
		str = my_strjoin(str, av[i]);
		i++;
	}
	p->size = count_numbers(str) - 1;
	p->indicea = p->size;
	p->indiceb = -1;
	p->stacka = malloc(sizeof(int) * (p->size + 1));
	p->stackb = malloc(sizeof(int) * (p->size + 1));
	check_fct(str, p);
	return (str);
}

void	fill(t_stacks *p, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
		{
			max_int_check(str, i, p);
			p->stacka[j] = my_atoi(str, i);
			j++;
		}
		while (str[i] != ' ' && str[i])
			i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	p;
	char		*str;
	int			i;

	i = 0;
	if (ac == 1)
		exit (0);
	if (!(av[1][0]))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	str = check_and_alloc(&p, ac, av);
	fill(&p, str);
	same_num_check(&p, p.size, str);
	if (p.size + 1 <= 3)
		sort_3(&p, 1);
	else if (p.size + 1 <= 5)
		sort_5(&p);
	else if (p.size + 1 <= 100)
		sort_100(&p);
	else
		sort_500(&p);
	free(str);
	return (0);
}
