/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:42:58 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:43:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_rx_to_max(t_stack **s, int min_s)
{
	int		distance_rs;
	t_stack	*curr;

	distance_rs = 0;
	curr = *s;
	while (curr->val != min_s)
	{
		distance_rs++;
		curr = curr->next;
	}
	return (distance_rs);
}

//	finds alternative neighbouring values in b stack if their insertion to a
//	would be more efficient than the current
void	cheap_neighbour_asc(t_stack **a, t_stack **b, int *rot)
{
	int	rot_rb;
	int	rot_rrb;

	rot_rb = cost_asc(a, (*b)->next->val, min_v(a), max_v(a));
	if (((*b)->next->sentry_min || (*b)->next->sentry_max) && \
			(list_size(b) > list_size(a)))
		rot_rb = INT_MAX - 1;
	if ((absolute(rot_rb) + 1) < absolute(*rot))
	{
		rb(b, 1);
		*rot = rot_rb;
	}
	rot_rrb = cost_asc(a, last_node(b)->val, min_v(a), max_v(a));
	if ((last_node(b)->sentry_min || last_node(b)->sentry_max) && \
			(list_size(b) > list_size(a)))
		rot_rrb = INT_MAX - 1;
	if ((absolute(rot_rrb) + 1) < absolute(*rot))
	{
		rrb(b, 1);
		*rot = rot_rrb;
	}
}

int	target_asc(t_stack **a, int insert, int min_a, int max_a)
{
	int		target;
	t_stack	*curr;

	curr = *a;
	if (insert > max_a || insert < min_a)
		target = min_a;
	else
	{
		target = max_a;
		while (curr)
		{
			if ((insert < curr->val) && (curr->val < target))
				target = curr->val;
			curr = curr->next;
		}
	}
	return (target);
}

//	returns an integer signifying the cost to rotate to the target
//	value in stack a for a given integer from b. A positive number
//	signifies the number of ra required, negative signifies rra.
int	cost_asc(t_stack **a, int insert, int min_a, int max_a)
{
	int		distance_ra;
	t_stack	*curr;

	curr = *a;
	distance_ra = 0;
	if (insert > max_a)
		distance_ra = n_rx_to_max(a, min_a);
	else
	{
		while (curr && curr->val != min_v(a) && insert < curr->val)
		{
			curr = curr->next;
			distance_ra++;
		}
		while (curr && insert > curr->val)
		{
			curr = curr->next;
			distance_ra++;
		}
	}
	if (distance_ra < ((int)(list_size(a) / 2) + 1))
		return (distance_ra);
	else
		return (distance_ra - (int)list_size(a));
}
