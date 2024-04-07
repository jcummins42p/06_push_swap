/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 13:30:06 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slow_sort(t_stack **a, t_stack **b)
{
	int	a_min;
	int	a_max;

	a_min = min_value(a);
	a_max = max_value(a);
	populate_b(a, b, 3);
	sort_three_asc_a(a);
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
