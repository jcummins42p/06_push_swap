/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/05 22:56:39 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_stack **s)
{
	t_stack	*curr;
	int		min;

	curr = *s;
	if (curr == NULL)
		return (0);
	min = curr->val;
	while (curr)
	{
		if (min > curr->val)
			min = curr->val;
		curr = curr->next;
	}
	return (min);
}

int	max_value(t_stack **s)
{
	t_stack	*curr;
	int		max;

	curr = *s;
	if (curr == NULL)
		return (0);
	max = curr->val;
	while (curr)
	{
		if (max < curr->val)
			max = curr->val;
		curr = curr->next;
	}
	return (max);
}

void	slow_sort(t_stack **a, t_stack **b)
{
	int	a_min;
	int	a_max;

	a_min = min_value(a);
	a_max = max_value(a);
	while (*b)
	{
		/*draw_stacks(a, b);*/
		while (last_node(a)->val < (*a)->val)
			rra(a, 1);
		if (*b && ((*b)->val > a_max && (*a)->val == a_min))
		{
			pa(b, a);
			ra(a, 1);
		}
		while (*b && ((*b)->val > (*a)->val && (*b)->val < a_max))
			ra(a, 1);
		if (*b && ((*b)->val < (*a)->val))
			pa(b, a);
		a_min = min_value(a);
		a_max = max_value(a);
	}
	while ((*a)->val > last_node(a)->val)
		rra(a, 1);
	/*draw_stacks(a, b);*/
}
