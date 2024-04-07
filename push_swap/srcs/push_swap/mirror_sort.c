/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 18:55:40 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	direction returns a positive number of required ra, or
//	a negative number of required rra to get to target in a
void	mirror_sort(t_stack **a, t_stack **b)
{
	int	rotate_by;
	int	rotate_by_rs;
	int	rotate_by_rrs;
	int	half_a;
	int	i;

	i = 0;
	half_a = list_size(a) / 2;
	rotate_by_rs = 0;
	rotate_by_rrs = 0;
	rotate_by = 0;
	populate_b(a, b, list_size(a) - 3);
	/*draw_stacks(a, b);*/
	sort_three_desc_b(b);
	/*draw_stacks(a, b);*/
	while (i < half_a)
	{
		/*draw_stacks(a, b);*/
		rotate_by = dir_ins_descending(b, (*a)->val);
		if ((*a)->next)
		{
			rotate_by_rs = dir_ins_descending(b, (*a)->next->val);
			if ((absolute(rotate_by_rs) + 1 ) < absolute(rotate_by))
			{
				ra(a, 1);
				rotate_by = rotate_by_rs;
			}
			rotate_by_rrs = dir_ins_descending(b, last_node(a)->val);
			if ((absolute(rotate_by_rrs) + 1) < absolute(rotate_by))
			{
				rra(a, 1);
				rotate_by = rotate_by_rrs;
			}
		}
		if (rotate_by > 0)
			while (rotate_by-- > 0)
				rb(b, 1);
		else if (rotate_by < 0)
			while (rotate_by++ < 0)
				rrb(b, 1);
		pb(a, b);
		i++;
	}
	rotate_by_rs = 0;
	rotate_by_rrs = 0;
	rotate_by = 0;
	/*populate_b_desc(a, b, 3);*/
	populate_b(a, b, 3);
	/*draw_stacks(a, b);*/
	sort_three_asc_a(a);
	while (*b)
	{
		/*draw_stacks(a, b);*/
		if ((*b)->val == min_value(b) && (*b)->next)
			rb(b, 1);
		if ((*b)->val == max_value(b) && (*b)->next)
			rrb(b, 1);
		rotate_by = dir_ins_ascending(a, (*b)->val);
		if ((*b)->next)
		{
			rotate_by_rs = dir_ins_ascending(a, (*b)->next->val);
			if ((absolute(rotate_by_rs) + 1 ) < absolute(rotate_by))
			{
				rb(b, 1);
				rotate_by = rotate_by_rs;
			}
			rotate_by_rrs = dir_ins_ascending(a, last_node(b)->val);
			if ((absolute(rotate_by_rrs) + 1) < absolute(rotate_by))
			{
				rrb(b, 1);
				rotate_by = rotate_by_rrs;
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
	while ((*a)->val > last_node(a)->val)
		ra(a, 1);
	/*draw_stacks(a, b);*/
}
