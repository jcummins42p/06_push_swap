/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:31 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/12 11:20:06 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_cost(t_stack *a, t_stack *b, long size_a, long size_b)
{
	long	index_a;
	long	index_b;

	index_a = (long)a->index;
	index_b = (long)b->index;
	b->cost = 0;
	if ((long)b->index < (size_b / 2))
		while (index_a-- > 0 || index_b-- > 0)
			b->cost++;
	else
		while (index_a++ < size_a || index_b++ < size_b)
			b->cost++;
}

void	find_costs(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	size_t	size_a;
	size_t	size_b;

	size_a = list_size(a);
	size_b = list_size(b);
	curr = *b;
	while (curr)
	{
		curr->target = target_asc(a, curr->val, min_v(a), max_v(a));
		if (curr->index > (size_b / 2) && \
				find_node(a, curr->target)->index > (size_a / 2))
			rr_cost(find_node(a, curr->target), curr, \
				list_size(a), list_size(b));
		else if (curr->index > (size_b / 2))
			curr->cost = (size_b - curr->index)
				+ find_node(a, curr->target)->index;
		else if (find_node(a, curr->target)->index > (size_a / 2))
			curr->cost = curr->index
				+ (size_a - find_node(a, curr->target)->index);
		else
			rr_cost(find_node(a, curr->target), curr, \
				list_size(a), list_size(b));
		curr = curr->next;
	}
}

void	set_indices(t_stack **a, t_stack **b)
{
	t_stack			*curr;
	unsigned int	i;

	curr = *a;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
	curr = *b;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

void	select_insert(t_stack **a, t_stack **b)
{
	populate_b(a, b, 3);
	sort_three(a, 1);
	set_indices(a, b);
	find_costs(a, b);
	draw_targets(a, b);
}
