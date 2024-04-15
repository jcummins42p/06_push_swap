/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:47:26 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:33 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

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

//		stack_utils_bonus.c
size_t			list_size(t_stack **s);
t_stack			*last_node(t_stack **a);
int				new_node(t_stack **a, int n);
void			list_clear(t_stack **a);
int				list_init(t_stack **a, char **argv);

//		ft_itoa_pad.c
char			*ft_itoa_pad(int n, int pad);

//		ft_printf.c
int				ft_printf(const char *str, ...);

//		ft_strncmp.c
int				ft_strncmp(const char *s1, const char *s2, size_t n);

//		ft_itoa.c
char			*ft_itoa(int n);

//		ft_split.c	-	To format input given as a single string into argv arr.
char			**ft_split(char const *s, char c);

//		visualise.c
void			draw_stacks(t_stack **a, t_stack **b);

//		validation.c	-	input checks
long int		ft_atol(char const *str);
int				valid_range(long n);
int				valid_uniq(t_stack **a, int n);
int				valid_numb(char **argv);

//		push.c
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);

//		swap.c
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

//		rotate.c
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

//		rev_rotate.c
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

//		sort_checks.c
int				check_reverse(t_stack **a);
int				check_sorted(t_stack **a);

#endif
