/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:44:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:44:12 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	\
	execute_rr(t_stack **a, t_stack **b, size_t a_index, size_t b_index)
{
	while (a_index > 0 && b_index > 0)
	{
		a_index--;
		b_index--;
		rr(a, b);
	}
	while (a_index > 0)
	{
		a_index--;
		ra(a, 1);
	}
	while (b_index > 0)
	{
		b_index--;
		rb(b, 1);
	}
}

static void	\
	execute_rrr(t_stack **a, t_stack **b, size_t a_index, size_t b_index)
{
	while (a_index < list_size(a) && b_index < list_size(b))
	{
		a_index++;
		b_index++;
		rrr(a, b);
	}
	while (a_index < list_size(a))
	{
		a_index++;
		rra(a, 1);
	}
	while (b_index < list_size(b))
	{
		b_index++;
		rrb(b, 1);
	}
}

static void	\
	execute_mixed(t_stack **a, t_stack **b, size_t a_index, size_t b_index)
{
	if (a_index < (list_size(a) + 1) / 2 && b_index >= (list_size(b) + 1) / 2)
	{
		while (a_index-- > 0)
			ra(a, 1);
		while (b_index++ < list_size(b))
			rrb(b, 1);
	}
	else
	{
		while (a_index++ < list_size(a))
			rra(a, 1);
		while (b_index-- > 0)
			rb(b, 1);
	}
}

static void	\
	execute(t_stack **a, t_stack **b, size_t a_index, size_t b_index)
{
	if (b_index <= (list_size(b)) / 2 && a_index <= (list_size(a)) / 2)
		execute_rr(a, b, a_index, b_index);
	else if (b_index > (list_size(b)) / 2 && a_index > (list_size(a)) / 2)
		execute_rrr(a, b, a_index, b_index);
	else
		execute_mixed(a, b, a_index, b_index);
	pa(b, a);
}

void	rotate_cheapest(t_stack **a, t_stack **b)
{
	size_t	a_index;
	size_t	b_index;
	t_stack	*cheapest_b;

	cheapest_b = cheapest_node(b);
	b_index = cheapest_b->index;
	a_index = find_node(a, (cheapest_b)->target)->index;
	execute(a, b, a_index, b_index);
}
