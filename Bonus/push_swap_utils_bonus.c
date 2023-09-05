/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:37:38 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/07 22:06:32 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	my_atoi(char *str, int i)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else
			i++;
	}
	while (str[i] && str[i] != ' ')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 2);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = ' ';
	i++;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}

void	ft_putstr(char *str)
{
	write(2, &str[0], ft_strlen(str));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	j;

	j = 0;
	while (s1[j] || s2[j])
	{
		if (s1[j] != s2[j])
			return (1);
		j++;
	}
	return (0);
}

void	free_fct(t_stacks *p, char *str, char *s)
{
	if (s)
		free(s);
	get_next_line(-1);
	free(str);
	error(p);
}
