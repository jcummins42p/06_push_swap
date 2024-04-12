/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:31 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/12 22:13:12 by jcummins         ###   ########.fr       */
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
	if ((long)b->index <= (size_b / 2))
		while (index_a > 0 || index_b > 0)
		{
			b->cost++;
			index_a--;
			index_b--;
		}
	else
		while (index_a < size_a || index_b < size_b)
		{
			b->cost++;
			index_a++;
			index_b++;
		}
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
		if (curr->index > ((size_b) / 2) && \
				find_node(a, curr->target)->index > (size_a) / 2)
			rr_cost(find_node(a, curr->target), curr, \
				list_size(a), list_size(b));
		else if (curr->index > (size_b) / 2)
			curr->cost = (size_b - curr->index)
				+ find_node(a, curr->target)->index;
		else if (find_node(a, curr->target)->index > (size_a) / 2)
			curr->cost = curr->index
				+ (size_a - find_node(a, curr->target)->index);
		else
			rr_cost(find_node(a, curr->target), curr, \
				size_a, size_b);
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
		curr->target = INT_MAX;
		curr->cost = INT_MAX;
		curr = curr->next;
	}
}

t_stack	*cheapest_node(t_stack **b)
{
	t_stack	*curr;
	t_stack	*output;
	size_t	cheapest;

	curr = *b;
	output = curr;
	cheapest = curr->cost;
	while (curr)
	{
		if (curr->cost < cheapest)
		{
			cheapest = curr->cost;
			output = curr;
		}
		curr = curr->next;
	}
	return (output);
}

void	select_insert(t_stack **a, t_stack **b)
{
	populate_b(a, b, 3);
	sort_three(a, 1);
	while (*b)
	{
		set_indices(a, b);
		find_costs(a, b);
		rotate_cheapest(a, b);
	}
	final_sort_a(a);
}
