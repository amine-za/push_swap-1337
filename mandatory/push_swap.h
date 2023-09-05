/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:55 by azaghlou          #+#    #+#             */
/*   Updated: 2023/04/07 22:36:38 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		max_int_check(char *str, int i, t_stacks *p);
void	args_check(char *str, t_stacks *p, char *s);
void	same_num_check(t_stacks *p, int x, char *str);
int		*check_fct(char *str, t_stacks *p);
void	ft_putstr(char *str);
void	error(t_stacks *p);
int		*arranging(t_stacks *p);
int		if_arranged(t_stacks *p);
int		check_j(t_stacks *p, int j, int i);
int		sa(t_stacks *p, int i);
int		sb(t_stacks *p, int i);
void	ss(t_stacks *p);
int		pa(t_stacks *p);
int		pb(t_stacks *p);
int		ra(t_stacks *p, int i);
int		rb(t_stacks *p, int i);
void	rr(t_stacks *p);
int		rra(t_stacks *p, int i);
int		rrb(t_stacks *p, int i);
void	rrr(t_stacks *p);
int		sort_3(t_stacks *p, int j);
int		sort_5(t_stacks *p);
void	sort_100(t_stacks *p);
void	sort_500(t_stacks *p);
void	free_fct(t_stacks *p, char *str, int i);

#endif