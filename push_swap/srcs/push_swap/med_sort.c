/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/06 23:10:25 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	direction returns a positive number of required ra, or
//	a negative number of required rra to get to target in a
int	direction(t_stack **a, int insert)
{
	int		distance_ra;
	int		distance_rra;
	int		target;
	t_stack *curr;

	curr = *a;
	target = min_value(a);
	distance_ra = 0;
	distance_rra = 0;
	if (insert > max_value(a))
	{
		target = min_value(a);
		while (curr->val != target)
		{
			distance_ra++;
			curr = curr->next;
		}
	}
	else
	{
		target = max_value(a);
		distance_ra = 0;
		while (curr && curr->val != min_value(a) && insert < curr->val)
		{
			curr = curr->next;
			distance_ra++;
		}
		while (curr && insert > curr->val)
		{
			target = curr->val;
			distance_ra++;
			curr = curr->next;
		}
		if (curr)
			target = curr->val;
	}
	distance_rra = list_size(a) - distance_ra;
	if (distance_rra > distance_ra)
		return (distance_ra);
	else
		return (0 - distance_rra);
}

void	med_sort(t_stack **a, t_stack **b)
{
	int	rotate_by;
	int	rotate_by_rb;
	int	rotate_by_rrb;

	rotate_by_rb = 0;
	rotate_by_rrb = 0;
	rotate_by = 0;
	while (*b)
	{
		/*draw_stacks(a, b);*/
		rotate_by = direction(a, (*b)->val);
		if ((*b)->next)
		{
			rotate_by_rb = direction(a, (*b)->next->val);
			if ((absolute(rotate_by_rb) + 1 ) < absolute(rotate_by))
			{
				rb(b, 1);
				rotate_by = rotate_by_rb;
			}
			rotate_by_rrb = direction(a, last_node(b)->val);
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
	while ((*a)->val > last_node(a)->val)
		ra(a, 1);
	/*draw_stacks(a, b);*/
}
