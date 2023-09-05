/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:48:10 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/06 22:19:58 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_positive_int(char *str, int i, t_stacks *p, int j)
{
	char	*max;

	max = "2147483647";
	if (str[i] != '-')
	{
		if (str[i] == '+')
			i++;
		while (str[i] == '0')
			i++;
		while (str[i + j] != ' ' && str[i + j])
			j++;
		if (j < 10)
			return (0);
		else if (j == 10)
		{
			j = 0;
			while (str[i + j] == max[j] && str[i + j] != ' ')
				j++;
			if (str[i + j] > max[j] && j < 10)
				free_fct(p, str, 0);
		}
		else
			free_fct(p, str, 0);
	}
	return (0);
}

int	max_negative_int(char *str, int i, t_stacks *p, int j)
{
	char	*min;

	min = "2147483648";
	if (str[i] == '-')
	{
		i++;
		while (str[i + j] == '0')
			i++;
		while (str[i + j] != ' ' && str[i + j])
			j++;
		if (j < 10)
			return (0);
		else if (j == 10)
		{
			j = 0;
			while (str[i + j] == min[j] && str[i + j] != ' ' && min[j])
				j++;
			if (str[i + j] > min[j] && j < 10)
				free_fct(p, str, 0);
		}
		else
			free_fct(p, str, 0);
	}
	return (0);
}

int	max_int_check(char *str, int i, t_stacks *p)
{
	int	j;

	j = 0;
	if (str[i] != '-')
		max_positive_int(str, i, p, j);
	else if (str[i] == '-')
		max_negative_int(str, i, p, j);
	return (0);
}
