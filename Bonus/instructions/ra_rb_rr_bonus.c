/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:04:22 by azaghlou          #+#    #+#             */
/*   Updated: 2023/03/09 11:04:43 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ra(t_stacks *p)
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
	return (0);
}

int	rb(t_stacks *p)
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
	return (0);
}

void	rr(t_stacks *p)
{
	ra(p);
	rb(p);
}
