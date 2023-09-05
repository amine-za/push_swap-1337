/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:53:55 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/08 16:21:43 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stacks
{
	int	indicea;
	int	indiceb;
	int	*stacka;
	int	*stackb;
	int	size;
}		t_stacks;

int		my_atoi(char *str, int i);
int		ft_strlen(char *str);
char	*my_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		max_int_check(char *str, int i, t_stacks *p);
void	args_check(char *str, t_stacks *p, char *s);
void	same_num_check(t_stacks *p, int x, char *str);
int		*check_fct(char *str, t_stacks *p);
void	ft_putstr(char *str);
void	error(t_stacks *p);
int		*arranging(t_stacks *p);
int		if_arranged(t_stacks *p);
void	free_fct(t_stacks *p, char *str, char *s);
int		sa(t_stacks *p);
int		sb(t_stacks *p);
void	ss(t_stacks *p);
int		pa(t_stacks *p);
int		pb(t_stacks *p);
int		ra(t_stacks *p);
int		rb(t_stacks *p);
void	rr(t_stacks *p);
int		rra(t_stacks *p);
int		rrb(t_stacks *p);
void	rrr(t_stacks *p);

#endif