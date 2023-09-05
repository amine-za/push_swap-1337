/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:05:39 by azaghlou          #+#    #+#             */
/*   Updated: 2023/05/24 15:05:03 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_from_btoa(t_stacks *p, int i, int j, int *arr)
{
	while (p->indiceb >= 0)
	{
		while (p->stackb[i] != arr[j])
			i++;
		if (i <= p->indiceb / 2)
		{
			while (p->stackb[0] != arr[j])
				rb(p, 0);
			pa(p);
		}
		else if (i > p->indiceb / 2)
		{
			while (p->stackb[0] != arr[j])
				rrb(p, 0);
			pa(p);
		}
		j--;
		i = 0;
	}
}

void	sort_100_atob(t_stacks *p, int i, int j, int *arr)
{
	while (p->indicea >= 0)
	{
		while (p->stacka[0] != arr[i])
			i++;
		if (i >= j && i <= j + 15)
		{
			pb(p);
			j++;
			// j = check_j(p, j, 16);
		}
		else if (i < j)
		{
			pb(p);
			// i = 0;
			// while (p->stacka[0] != arr[i])
			// 	i++;
			// if (i > j + 15)
			// 	rr(p);
			// else
			rb(p, 0);
			j = check_j(p, j, 16);
		}
		else if (i > j + 15)
			ra(p, 0);
		i = 0;
	}
}

void	sort_100(t_stacks *p)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	if (if_arranged(p) == 0)
	{
		free(p->stacka);
		free(p->stackb);
		return ;
	}
	arr = arranging(p);
	sort_100_atob(p, i, j, arr);
	i = 0;
	j = p->size;
	best_move_from_btoa(p, i, j, arr);
	free(arr);
	free(p->stacka);
	free(p->stackb);
}

void	sort_500_atob(t_stacks *p, int i, int j, int *arr)
{
	while (p->indicea >= 0)
	{
		while (p->stacka[0] != arr[i])
			i++;
		if (i >= j && i <= j + 36)
		{
			pb(p);
			j = check_j(p, j, 37);
		}
		else if (i < j)
		{
			pb(p);
			i = 0;
			while (p->stacka[0] != arr[i])
				i++;
			if (i > j + 36)
				rr(p);
			else
				rb(p, 0);
			j = check_j(p, j, 37);
		}
		else if (i > j + 36)
			ra(p, 0);
		i = 0;
	}
}

void	sort_500(t_stacks *p)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	if (if_arranged(p) == 0)
	{
		free(p->stacka);
		free(p->stackb);
		return ;
	}
	arr = arranging(p);
	sort_500_atob(p, i, j, arr);
	i = 0;
	j = p->size;
    exit(0);
	best_move_from_btoa(p, i, j, arr);
	free(arr);
	free(p->stacka);
	free(p->stackb);
}
