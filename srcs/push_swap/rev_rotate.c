/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:42:27 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:42:30 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print_command)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penul;

	if (*a && (*a)->next)
	{
		first = (*a);
		last = last_node(a);
		penul = last->prev;
		if (penul)
			penul->next = NULL;
		last->next = first;
		first->prev = last;
		last->prev = NULL;
		*a = last;
	}
	if (print_command)
		ft_printf("rra\n");
	fflush(stdout);
}

void	rrb(t_stack **b, int print_command)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penul;

	if (*b && (*b)->next)
	{
		first = (*b);
		last = last_node(b);
		penul = last->prev;
		if (penul)
			penul->next = NULL;
		last->next = first;
		first->prev = last;
		last->prev = NULL;
		*b = last;
	}
	if (print_command)
		ft_printf("rrb\n");
	fflush(stdout);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rra(b, 0);
	ft_printf("rrr\n");
	fflush(stdout);
}
