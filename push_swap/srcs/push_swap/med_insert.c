/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/08 18:37:00 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	med insert finds the most effective rotation direction of stack a to insert
//	the current value of b, then compares it to the adjacent values held in b
//	from both the rb and rrb direction, and chooses the one which requires
//	fewest commands.

void	med_insert(t_stack **a, t_stack **b)
{
	int	rot;

	populate_b(a, b, 3);
	sort_three(a, 1);
	while (*b)
	{
		rot = cost_asc(a, (*b)->val, min_v(a), max_v(a));
		if ((*b)->next)
			cheap_neighbour_desc(a, b, &rot);
		if (rot > 0)
			while (rot-- > 0)
				ra(a, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rra(a, 1);
		pa(b, a);
	}
	final_sort(a);
}
