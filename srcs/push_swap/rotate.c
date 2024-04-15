/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:42:11 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:42:14 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int print_command)
{
	t_stack	*first;
	t_stack	*last;

	if (*a && (last_node(a) != *a))
	{
		first = (*a);
		if (first->next)
		{
			last = last_node(a);
			last->next = first;
			first->prev = last;
			first->next->prev = NULL;
			*a = first->next;
			first->next = NULL;
		}
	}
	if (print_command)
		ft_printf("ra\n");
	fflush(stdout);
}

void	rb(t_stack **b, int print_command)
{
	t_stack	*first;
	t_stack	*last;

	if (*b && (last_node(b) != *b))
	{
		first = (*b);
		if (first->next)
		{
			last = last_node(b);
			last->next = first;
			first->prev = last;
			first->next->prev = NULL;
			*b = first->next;
			first->next = NULL;
		}
	}
	if (print_command)
		ft_printf("rb\n");
	fflush(stdout);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
	fflush(stdout);
}
