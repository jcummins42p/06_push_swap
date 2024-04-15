/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:47:26 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 15:58:33 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				val;
	int				target;
	size_t			index;
	size_t			cost;
	char			*sentry_min;
	char			*sentry_max;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//		stack_init.c
int				new_node(t_stack **a, int n);
void			list_clear(t_stack **a);
int				list_init(t_stack **a, char **argv);

//		stack_info.c
int				min_v(t_stack **s);
int				max_v(t_stack **s);
t_stack			*find_node(t_stack **s, int search);
t_stack			*last_node(t_stack **a);
size_t			list_size(t_stack **s);

//		ft_printf.c
int				ft_printf(const char *str, ...);

//		ft_itoa.c
char			*ft_itoa(int n);

//		ft_itoa_pad.c
unsigned int	absolute(int n);
char			*ft_itoa_pad(int n, int pad);

//		visualise.c
void			draw_stacks(t_stack **a, t_stack **b);
void			draw_targets(t_stack **a, t_stack **b);

//		ft_split.c	-	To format input given as a single string into argv arr.
char			**ft_split(char const *s, char c);

//		validation.c	-	input checks
long int		ft_atol(char const *str);
int				valid_range(long n);
int				valid_uniq(t_stack **a, int n);
int				valid_numb(char **argv);

//		push.c
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);

//		swap.c
void			sa(t_stack **a, int print_command);
void			sb(t_stack **b, int print_command);
void			ss(t_stack **a, t_stack **b);

//		rotate.c
void			ra(t_stack **a, int print_command);
void			rb(t_stack **b, int print_command);
void			rr(t_stack **a, t_stack **b);

//		rev_rotate.c
void			rra(t_stack **a, int print_command);
void			rrb(t_stack **b, int print_command);
void			rrr(t_stack **a, t_stack **b);

//		cost_calc_asc.c	-	return number of rotations and most efficient
//							direction to insert a given integer in target
//							stack
void			cheap_neighbour_asc(t_stack **a, t_stack **b, int *rot);
int				target_asc(t_stack **a, int insert, int min_a, int max_a);
int				cost_asc(t_stack **a, int insert, int min_a, int max_a);

//		cost_calc_desc.c
void			cheap_neighbour_desc(t_stack **a, t_stack **b, int *rot);
int				cost_desc(t_stack **b, int insert, int min_b, int max_b);

//		sort_utils.c	- general sort functions used by multiple algorithms
void			populate_b(t_stack **a, t_stack **b, int remain);
void			sort_three(t_stack **s, int direction);
void			final_sort_a(t_stack **a);
void			final_sort_b(t_stack **b);

//		sort_checks.c
int				check_reverse(t_stack **a);
int				check_sorted(t_stack **a);

//		slow_insert.c
void			slow_insert(t_stack **a, t_stack **b);

//		med_insert.c	-	the previous insert sort with optimisation to pick
//							an efficient direction for each insertion, plus
//							rotating by rb or rrb once to find a less expensive
//							insert number.
void			med_insert(t_stack **a, t_stack **b);

//		mirror_insert.c	-	mirror sorts half of a into b, then the other half
//							is sorted back into a. Reduces time spent searching
//							through a large sorted stack.
void			sorted_to_a(t_stack **a, t_stack **b);
void			sort_into_a(t_stack **a, t_stack **b);
void			sort_into_b(t_stack **a, t_stack **b);
void			mirror_insert(t_stack **a, t_stack **b);

//		group_push.c	-	pushes integers to b in range groups rather than
//							all together, to make future sorting more efficient
void			group_push(t_stack **a, t_stack **b);

//		select_insert.c	-	finds the target a value for each value in b, finds
//							the total action cost for each, and executes that
t_stack			*cheapest_node(t_stack **b);
void			select_insert(t_stack **a, t_stack **b);

//		slect_execute.c	-	eexecutes the rotations and insertion based on the
//							calculated cheapest option from select_insert.
//void			execute(t_stack **a, t_stack **b, size_t size_a, size_t size_b);
void			rotate_cheapest(t_stack **a, t_stack **b);

#endif
