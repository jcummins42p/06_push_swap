/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:02 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/02 19:02:13 by jcummins         ###   ########.fr       */
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
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);

//		swap.c
void			sa(t_stack **a, int print_command);
void			sb(t_stack **b, int print_command);
void			ss(t_stack **a, t_stack **b);

//		rotate.c
void			ra(t_stack **a, int print_command);
void			ra(t_stack **b, int print_command);
void			rr(t_stack **a, t_stack **b);

//		rev_rotate.c
void			rra(t_stack **a, int print_command);
void			rrb(t_stack **b, int print_command);
void			rrr(t_stack **a, t_stack **b);

//		visualise.c
void			draw_stacks(t_stack **a, t_stack **b);
char			*draw_by_index(t_stack **s, size_t index);
void			list_print(t_stack **a);

//		sort_checks.c
int				check_reverse(t_stack **a);
int				check_sorted(t_stack **a);

//		sort.c
void			populate_b(t_stack **a, t_stack **b, int remain);
void			ft_sort(t_stack **a);

//		main.c
void			argv_free(char **argv);

#endif
