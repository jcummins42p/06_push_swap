/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 13:29:00 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	med_sort(t_stack **a, t_stack **b)
{
	int	rotate_by;
	int	rotate_by_rb;
	int	rotate_by_rrb;

	rotate_by_rb = 0;
	rotate_by_rrb = 0;
	rotate_by = 0;
	populate_b(a, b, 3);
	sort_three_asc_a(a);
	while (*b)
	{
		/*draw_stacks(a, b);*/
		rotate_by = dir_ins_ascending(a, (*b)->val);
		if ((*b)->next)
		{
			rotate_by_rb = dir_ins_ascending(a, (*b)->next->val);
			if ((absolute(rotate_by_rb) + 1 ) < absolute(rotate_by))
			{
				rb(b, 1);
				rotate_by = rotate_by_rb;
			}
			rotate_by_rrb = dir_ins_ascending(a, last_node(b)->val);
			if ((absolute(rotate_by_rrb) + 1) < absolute(rotate_by))
			{
				rrb(b, 1);
				rotate_by = rotate_by_rrb;
			}
		}
		if (rotate_by > 0)
			while (rotate_by-- > 0)
				ra(a, 1);
		else if (rotate_by < 0)
			while (rotate_by++ < 0)
				rra(a, 1);
		pa(b, a);
	}
	rotate_by = dir_ins_ascending(a, min_value(a) - 1);
	if (rotate_by > 0)
		while (rotate_by-- > 0)
			ra(a, 1);
	else if (rotate_by < 0)
		while (rotate_by++ < 0)
			rra(a, 1);
	/*draw_stacks(a, b);*/
}
