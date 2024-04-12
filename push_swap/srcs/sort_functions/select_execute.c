/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:56:05 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/12 12:57:49 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr(t_stack **a, t_stack **b)
{
	while ((*a)->index > 0 && (*b)->index > 0)
	{
		(*a)->index--;
		(*b)->index--;
		rr(a, b);
	}
	while ((*a)->index > 0)
	{
		(*a)->index--;
		ra(a, 1);
	}
	while ((*b)->index > 0)
	{
		(*b)->index--;
		rb(b, 1);
	}
	pa(b, a);
}

void	execute_rrr(t_stack **a, t_stack **b, size_t size_a, size_t size_b)
{
	while ((*a)->index < size_a && (*b)->index < size_b)
	{
		(*a)->index++;
		(*b)->index++;
		rrr(a, b);
	}
	while ((*a)->index < size_a)
	{
		(*a)->index++;
		rra(a, 1);
	}
	while ((*b)->index < size_b)
	{
		(*b)->index++;
		rrb(b, 1);
	}
	pa(b, a);
}

void	execute(t_stack **a, t_stack **b, size_t size_a, size_t size_b)
{

	if (b->index < (size_b / 2))
		execute_rr(a, b)
	else
		execute_rrr(a, b);
}

void	rotate_cheapest(t_stack **a, t_stack **b)
{
	t_stack *target_a;
	t_stack *target_b;

	target_b = cheapest_node(a, b);
	target_a = find_node(a, target_b->target);
	ft_printf("Value %d (index %d) will be pushed to value %d (index %d)", target_b->val, target_b->index, target_a->val, target_a->index);
}
