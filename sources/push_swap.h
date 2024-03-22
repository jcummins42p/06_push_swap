/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:02 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 18:41:32 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//		ft_split.c
char			**ft_split(char const *s, char c);
//		utils.c
long int		ft_atol(char const *str);
int				isnum(char c);
//		validation.c
int				valid_range(long n);
int				valid_uniq(t_stack **a, int n);
int				valid_numb(char **argv);
//		stack_init.c
t_stack			*last_node(t_stack **a);
int				app_node(t_stack **a, int n);
void			list_node(t_stack **a);
void			stack_clear(t_stack **a);
int				stack_init(t_stack **a, char **argv);
//		push.c
void			push(t_stack **a, t_stack **b);
//		swap.c
void			swap(t_stack **s);
//		rotate.c
void			rote(t_stack **s);
void			rrot(t_stack **s);

#endif
