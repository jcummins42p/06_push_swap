/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/02 19:05:36 by jcummins         ###   ########.fr       */
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
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rra(b, 0);
	ft_printf("rrr\n");
}
