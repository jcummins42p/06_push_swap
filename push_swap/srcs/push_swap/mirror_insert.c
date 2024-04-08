/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/08 19:20:39 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	direction returns a positive number of required ra, or
//	a negative number of required rra to get to target in a

static void	insort_to_a(t_stack **a, t_stack **b)
{
	int	rot;

	while (*b)
	{
		if ((*b)->val == min_v(b) && (*b)->next)
			rb(b, 1);
		if ((*b)->val == max_v(b) && (*b)->next)
			rrb(b, 1);
		rot = cost_asc(a, (*b)->val, min_v(a), max_v(a));
		/*if ((*b)->next)*/
			/*cheap_neighbour_asc(a, b, &rot);*/
		if (rot > 0)
			while (rot-- > 0)
				ra(a, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rra(a, 1);
		pa(b, a);
	}
}

//	sorts half of a into b in descending order, then flags the start and end
//	of this so that they are not sorted back into a before unsorted values
static void	insort_to_b(t_stack **a, t_stack **b)
{
	int	rot;
	int	half_a;
	int	i;

	i = 0;
	half_a = list_size(a) / 2;
	while (i < half_a)
	{
		rot = cost_desc(b, (*a)->val, min_v(b), max_v(b));
		if ((*a)->next)
			cheap_neighbour_desc(a, b, &rot);
		if (rot > 0)
			while (rot-- > 0)
				rb(b, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rrb(b, 1);
		pb(a, b);
		i++;
	}
	/*find_node(b, min_v(b))->sentry = min_v(b);*/
	/*find_node(b, max_v(b))->sentry = max_v(b);*/
}

void	mirror_insert(t_stack **a, t_stack **b)
{
	populate_b(a, b, list_size(a) - 3);
	sort_three(b, -1);
	insort_to_b(a, b);
	populate_b(a, b, 3);
	sort_three(a, 1);
	insort_to_a(a, b);
	final_sort(a);
}
