/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/10 13:47:30 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	pushes the all but 3 of the remaining a members to b without sorting
void	populate_b(t_stack **a, t_stack **b, int remain)
{
	int	i;

	i = 0;
	i = list_size(a);
	while (i > remain)
	{
		pb(a, b);
		i--;
	}
}

void	sort_three(t_stack **s, int direction)
{
	if (list_size(s) >= 3)
	{
		if (direction < 0)
		{
			if ((*s)->val < (*s)->next->val && (*s)->val < (*s)->next->next->val)
				rb(s, 1);
			else if ((*s)->val > (*s)->next->val && \
					(*s)->next->next->val > (*s)->next->val)
				rrb(s, 1);
			if ((*s)->val < (*s)->next->val)
				sb(s, 1);
		}
		else if (direction > 0)
		{
			if ((*s)->val > (*s)->next->val && (*s)->val > (*s)->next->next->val)
				ra(s, 1);
			else if ((*s)->val < (*s)->next->val && \
					(*s)->next->next->val < (*s)->next->val)
				rra(s, 1);
			if ((*s)->val > (*s)->next->val)
				sa(s, 1);
		}
	}
}

void	final_sort_b(t_stack **b)
{
	int	rotate_by;

	rotate_by = 0;
	if (!check_reverse(b))
	{
		rotate_by = cost_desc(b, min_v(b) - 1, min_v(b), max_v(b));
		if (rotate_by > 0)
			while (rotate_by-- > 0)
				rb(b, 1);
		else if (rotate_by < 0)
			while (rotate_by++ < 0)
				rrb(b, 1);
		while ((*b)->val < last_node(b)->val)
			rrb(b, 1);
	}
}

void	final_sort_a(t_stack **a)
{
	int	rotate_by;

	rotate_by = 0;
	if (!check_sorted(a))
	{
		rotate_by = cost_asc(a, min_v(a) - 1, min_v(a), max_v(a));
		if (rotate_by > 0)
			while (rotate_by-- > 0)
				ra(a, 1);
		else if (rotate_by < 0)
			while (rotate_by++ < 0)
				rra(a, 1);
		while ((*a)->val > last_node(a)->val)
			ra(a, 1);
	}
}
