/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:02 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/26 18:39:19 by jcummins         ###   ########.fr       */
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

//		ft_itoa_pad.c
int				n_digits(unsigned int n);
unsigned int	absolute(int n);
char			*empty_pad(int pad);
char			*printstr_pad(char *s, unsigned int n, int neg, int pad);
char			*ft_itoa_pad(int n, int pad);
//		ft_split.c
char			**ft_split(char const *s, char c);
//		utils.c
long int		ft_atol(char const *str);
int				isnum(char c);
//		validation.c
int				valid_range(long n);
int				valid_uniq(t_stack **a, int n);
int				valid_numb(char **argv);
//		stack_utils.c
t_stack			*last_node(t_stack **a);
size_t			list_size(t_stack **s);
int				new_node(t_stack **a, int n);
void			list_clear(t_stack **a);
int				list_init(t_stack **a, char **argv);
//		push.c
void			push(t_stack **a, t_stack **b);
//		swap.c
void			swap(t_stack **s);
//		rotate.c
void			rote(t_stack **s);
void			rrot(t_stack **s);
void			rr(t_stack **a, t_stack **b);
void			rrr(t_stack **a, t_stack **b);
//		visualise.c
void			draw_stacks(t_stack **a, t_stack **b);
char			*draw_by_index(t_stack **s, size_t index);
void			list_print(t_stack **a);
//		sort.c
void			populate_b(t_stack **a, t_stack **b);
int				check_sorted(t_stack **a);
void			ft_sort(t_stack **a);
//		main.c
void			argv_free(char **argv);

#endif
