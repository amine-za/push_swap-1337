/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:29:24 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/06 22:20:07 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arrange_norm(int i, int j, t_stacks *p, int *arr)
{
	int	swap;

	while (j <= p->indicea)
	{
		while (i > j)
		{
			if (arr[i] < arr[i - 1])
			{
				swap = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = swap;
			}
			i--;
		}
		j++;
		i = p->indicea;
	}
	return (arr);
}

int	*arranging(t_stacks *p)
{
	int	i;
	int	j;
	int	swap;
	int	*arr;

	i = 0;
	j = 0;
	arr = malloc(sizeof(int) * p->indicea + 1);
	while (i <= p->indicea)
	{
		arr[i] = p->stacka[i];
		i++;
	}
	i = p->indicea;
	return (arrange_norm(i, j, p, arr));
}

int	sort_3(t_stacks *p, int j)
{
	int	i;
	int	*arr;

	i = 0;
	if (if_arranged(p) == 0)
	{
		free_fct(p, NULL, 1);
		return (0);
	}
	arr = arranging(p);
	if (p->indicea == 2)
	{
		while (p->stacka[i] != arr[2] && i <= 2)
			i++;
		if (i == 0)
			ra(p, 0);
		if (i == 1)
			rra(p, 0);
	}
	if (p->stacka[1] == arr[0])
		sa(p, 0);
	if (j == 1)
		free_fct(p, NULL, 1);
	free(arr);
	return (0);
}

void	sort_5_norm(t_stacks *p, int *arr, int i, int y)
{
	while (p->indiceb != 1)
	{
		while (p->stacka[i] != arr[y])
			i++;
		if (i <= p->indicea / 2)
		{
			while (p->stacka[0] != arr[y])
				ra(p, 0);
			pb(p);
		}
		else
		{
			while (p->stacka[0] != arr[y])
				rra(p, 0);
			pb(p);
		}
		i = 0;
		y++;
	}
	free (arr);
}

int	sort_5(t_stacks *p)
{
	int	i;
	int	y;
	int	*arr;

	i = 0;
	y = 0;
	if (if_arranged(p) == 0)
	{
		free_fct(p, NULL, 1);
		return (0);
	}
	arr = arranging(p);
	sort_5_norm(p, arr, i, y);
	sort_3(p, 0);
	pa(p);
	pa(p);
	free(p->stacka);
	free(p->stackb);
	return (0);
}
