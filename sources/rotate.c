/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:54 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/25 15:38:18 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rote(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	if (*src && (last_node(src) != *src))
	{
		first = (*src);
		if (first->next)
		{
			last = last_node(src);
			last->next = first;
			first->prev = last;
			first->next->prev = NULL;
			*src = first->next;
			first->next = NULL;
		}
	}
}

void	rrot(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penul;

	if (*src && (*src)->next)
	{
		first = (*src);
		last = last_node(src);
		penul = last->prev;
		if (penul)
			penul->next = NULL;
		last->next = first;
		first->prev = last;
		last->prev = NULL;
		*src = last;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rote(a);
	rote(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrot(a);
	rrot(b);
}
