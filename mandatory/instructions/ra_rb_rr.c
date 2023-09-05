/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:34 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/10 17:07:45 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stacks *p, int i)
{
	int	j;
	int	x;

	j = 0;
	x = p->stacka[0];
	if (p->indicea < 1)
		return (0);
	while (j <= p->indicea)
	{
		p->stacka[j] = p->stacka[j + 1];
		j++;
	}
	p->stacka[p->indicea] = x;
	if (i == 0)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stacks *p, int i)
{
	int	j;
	int	x;

	j = 0;
	x = p->stackb[0];
	if (p->indiceb < 1)
		return (0);
	while (j <= p->indiceb)
	{
		p->stackb[j] = p->stackb[j + 1];
		j++;
	}
	p->stackb[p->indiceb] = x;
	if (i == 0)
		write(1, "rb\n", 3);
	return (0);
}

void	rr(t_stacks *p)
{
	ra(p, 1);
	rb(p, 1);
	write(1, "rr\n", 3);
}
