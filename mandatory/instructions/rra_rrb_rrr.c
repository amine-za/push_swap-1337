/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:20:12 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/10 18:14:44 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stacks *p, int i)
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
	if (i == 0)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stacks *p, int i)
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
	if (i == 0)
		write(1, "rrb\n", 4);
	return (0);
}

void	rrr(t_stacks *p)
{
	rra(p, 1);
	rrb(p, 1);
	write(1, "rrr\n", 4);
}
