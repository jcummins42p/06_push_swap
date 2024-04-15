/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:42:27 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 16:22:16 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rra(t_stack **a)
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
}

void	rrb(t_stack **b)
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
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rra(b);
}
