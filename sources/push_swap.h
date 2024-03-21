/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:02 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 14:32:49 by jcummins         ###   ########.fr       */
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

char			**ft_split(char const *s, char c);
long int		ft_atol(char const *str);
int				isnum(char c);
int				valid_in(char **argv);
void			stack_init(t_stack **a, char **argv);
int				isnum(char c);
int				valid_uniq(t_stack **a, int n);

#endif
