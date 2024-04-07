/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:02 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 14:23:17 by jcummins         ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//		ft_printf.c
int				ft_printf(const char *str, ...);

//		ft_itoa_pad.c
unsigned int	absolute(int n);
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

//		stack_info.c
int				min_value(t_stack **s);
int				max_value(t_stack **s);
t_stack			*last_node(t_stack **a);
size_t			list_size(t_stack **s);

//		stack_init.c
int				new_node(t_stack **a, int n);
void			list_clear(t_stack **a);
int				list_init(t_stack **a, char **argv);

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

//		visualise.c
void			draw_stacks(t_stack **a, t_stack **b);

//		sort_checks.c
int				check_reverse(t_stack **a);
int				check_sorted(t_stack **a);

//		slow_sort.c
void			slow_sort(t_stack **a, t_stack **b);

//		med_sort.c
void			med_sort(t_stack **a, t_stack **b);

//		med_sort.c
void			mirror_sort(t_stack **a, t_stack **b);

//		series_push.c
void			populate_b_desc(t_stack **a, t_stack **b, int remain);

//		sort.c
int				dir_ins_ascending(t_stack **a, int insert);
int				dir_ins_descending(t_stack **b, int insert);
void			populate_b(t_stack **a, t_stack **b, int remain);
void			sort_three_asc_a(t_stack **s);
void			sort_three_desc_b(t_stack **s);
void			ft_sort(t_stack **a);

//		main.c
void			argv_free(char **argv);

#endif
