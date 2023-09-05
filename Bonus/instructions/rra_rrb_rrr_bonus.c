/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:04:48 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/09 11:05:17 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	rra(t_stacks *p)
{
	int	j;
	int	x;

	j = p->indicea;
	x = p->stacka[p->indicea];
	if (p->indicea < 1)
		return (0);
	while (j >= 0)
	{
		p->stacka[j] = p->stacka[j - 1];
		j--;
	}
	p->stacka[0] = x;
	return (0);
}

int	rrb(t_stacks *p)
{
	int	j;
	int	x;

	j = p->indiceb;
	x = p->stackb[p->indiceb];
	if (p->indiceb < 1)
		return (0);
	while (j >= 0)
	{
		p->stackb[j] = p->stackb[j - 1];
		j--;
	}
	p->stackb[0] = x;
	return (0);
}

void	rrr(t_stacks *p)
{
	rra(p);
	rrb(p);
}
