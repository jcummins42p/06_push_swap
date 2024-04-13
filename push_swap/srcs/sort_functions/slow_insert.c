/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:44:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:44:24 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	slow insert returns to the lowest number in the stack between each insertion
//	then searches the whole list to locate the target insertion point.
//	It is very slow, and makes no attempts to find optimal paths
void	slow_insert(t_stack **a, t_stack **b)
{
	int	a_min;
	int	a_max;

	a_min = min_v(a);
	a_max = max_v(a);
	populate_b(a, b, 3);
	sort_three(a, 1);
	while (*b)
	{
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
		a_min = min_v(a);
		a_max = max_v(a);
	}
	while ((*a)->val > last_node(a)->val)
		rra(a, 1);
}
