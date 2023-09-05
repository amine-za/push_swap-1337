/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:28:29 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/07 22:01:54 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bonus/checker.h"

void	check_instructions(char *s, t_stacks *p, char *str)
{
	if (ft_strcmp(s, "pa\n") == 0)
		pa(p);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(p);
	else if (ft_strcmp(s, "sa\n") == 0)
		sa(p);
	else if (ft_strcmp(s, "sb\n") == 0)
		sb(p);
	else if (ft_strcmp(s, "ss\n") == 0)
		ss(p);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra(p);
	else if (ft_strcmp(s, "rb\n") == 0)
		rb(p);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(p);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra(p);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrb(p);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(p);
	else
		free_fct(p, str, s);
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
	str = malloc (1);
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
	char		*str;
	t_stacks	p;
	char		*s;

	if (ac == 1)
		exit(0);
	str = check_and_alloc(&p, ac, av);
	fill(&p, str);
	same_num_check(&p, p.size, str);
	s = get_next_line(0);
	while (s)
	{
		check_instructions(s, &p, str);
		free(s);
		s = get_next_line(0);
	}
	if (if_arranged(&p) == 0 && p.indiceb == -1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	get_next_line(-1);
	free(str);
	free(p.stacka);
	free(p.stackb);
	return (0);
}
