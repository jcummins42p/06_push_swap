/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/06 13:22:05 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	direction returns a positive number of required ra, or
//	a negative number of required rra to get to target in a
int	direction(t_stack **a, t_stack **b)
{
	int		distance_ra;
	int		distance_rra;
	int		insert;
	int		target;
	t_stack *curr;

	curr = *a;
	insert = (*b)->val;
	target = min_value(a);
	distance_ra = 0;
	if (insert > max_value(a))
	{
		target = min_value(a);
		while (curr->val > target)
		{
			distance_ra++;
			curr = curr->next;
		}
	}
	else
	{
		target = max_value(a);
		while (curr)
		{
			if (insert < curr->val && curr->val < target)
			{
				target = curr->val;
				distance_ra++;
			}
			curr = curr->next;
		}
	}
	distance_rra = list_size(a) - distance_ra;
	ft_printf("Target value is %d. ra would take %d rotations and rra would take %d\n", target, distance_ra, distance_rra);
	if (distance_rra > distance_ra)
		return (distance_ra);
	else
		return (0 - distance_rra);
}

void	med_sort(t_stack **a, t_stack **b)
{
	int	a_min;
	int	a_max;

	a_min = min_value(a);
	a_max = max_value(a);
	while (*b)
	{
		draw_stacks(a, b);
		if (direction(a, b) > 0)
		{
			while (*b && ((*b)->val > (*a)->val && (*b)->val < a_max))
			{
				ra(a, 1);
				if (*b && ((*b)->val < (*a)->val) && (*b)->val > last_node(a)->val)
					pa(b, a);
			}
		}
		else
		{
			if (*b && (((*b)->val < (*a)->val)) && (((*b)->val > last_node(a)->val) || last_node(a)->val == a_max))
				pa(b, a);
			while (last_node(a)->val < (*a)->val)
			{
				draw_stacks(a, b);
				direction(a, b);
				rra(a, 1);
				if (*b && (((*b)->val < (*a)->val)) && (((*b)->val > last_node(a)->val) || last_node(a)->val == a_max))
					pa(b, a);
				a_min = min_value(a);
				a_max = max_value(a);
			}
		}
		if (*b && ((*b)->val > a_max && (*a)->val == a_min))
		{
			pa(b, a);
			ra(a, 1);
		}
		a_min = min_value(a);
		a_max = max_value(a);
	}
	while ((*a)->val > last_node(a)->val)
		ra(a, 1);
	draw_stacks(a, b);
}
