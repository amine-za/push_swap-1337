/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:34:18 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/10 18:15:52 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stacks *p, int i)
{
	int	x;

	if (p->indicea >= 1)
	{
		x = p->stacka[1];
		p->stacka[1] = p->stacka[0];
		p->stacka[0] = x;
		if (i == 0)
			write(1, "sa\n", 3);
	}
	return (0);
}

int	sb(t_stacks *p, int i)
{
	int	x;

	if (p->indiceb >= 1)
	{
		x = p->stackb[1];
		p->stackb[1] = p->stackb[0];
		p->stackb[0] = x;
		if (i == 0)
			write(1, "sb\n", 3);
	}
	return (0);
}

void	ss(t_stacks *p)
{
	sa(p, 1);
	sb(p, 1);
	write(1, "ss\n", 3);
}

int	pa(t_stacks *p)
{
	int	x;
	int	i;

	if (p->indiceb == -1)
		return (0);
	x = p->stackb[0];
	i = 0;
	while (i <= p->size)
	{
		p->stackb[i] = p->stackb[i + 1];
		i++;
	}
	i = p->size - 1;
	while (i >= 0)
	{
		p->stacka[i + 1] = p->stacka[i];
		i--;
	}
	p->stacka[0] = x;
	p->indicea++;
	p->indiceb--;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stacks *p)
{
	int	x;
	int	i;

	if (p->indicea == -1)
		return (0);
	x = p->stacka[0];
	i = 0;
	while (i <= p->size)
	{
		p->stacka[i] = p->stacka[i + 1];
		i++;
	}
	i = p->size - 1;
	while (i >= 0)
	{
		p->stackb[i + 1] = p->stackb[i];
		i--;
	}
	p->stackb[0] = x;
	p->indiceb++;
	p->indicea--;
	write(1, "pb\n", 3);
	return (0);
}
