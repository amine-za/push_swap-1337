/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:34:18 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/17 19:02:41 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	sa(t_stacks *p)
{
	int	x;

	if (p->indicea >= 1)
	{
		x = p->stacka[1];
		p->stacka[1] = p->stacka[0];
		p->stacka[0] = x;
	}
	return (0);
}

int	sb(t_stacks *p)
{
	int	x;

	if (p->indiceb >= 1)
	{
		x = p->stackb[1];
		p->stackb[1] = p->stackb[0];
		p->stackb[0] = x;
	}
	return (0);
}

void	ss(t_stacks *p)
{
	sa(p);
	sb(p);
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
	return (0);
}
