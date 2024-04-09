/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:49:40 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/09 14:58:03 by jcummins         ###   ########.fr       */
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

//	cheaper_neighbour takes a look at the insertion cost of the two values in b
//	are only one rotation away, rotates b to put them at the head of the stack
//	and updates the rot variable with the new value and direction to the target.
void	cheap_neighbour_asc(t_stack **a, t_stack **b, int *rot)
{
	int	rot_rb;
	int	rot_rrb;

	//	rb is CORRECT because we are rotating the source array before the insert
	rot_rb = cost_asc(a, (*b)->next->val, min_v(a), max_v(a));
	if (((*b)->next->sentry_min || (*b)->next->sentry_max) && (list_size(b) > list_size(a)))
		rot_rb = INT_MAX - 1;
	if ((absolute(rot_rb) + 1) < absolute(*rot))
	{
		rb(b, 1);
		*rot = rot_rb;
	}
	rot_rrb = cost_asc(a, last_node(b)->val, min_v(a), max_v(a));
	if ((last_node(b)->sentry_min || last_node(b)->sentry_max) && (list_size(b) > list_size(a)))
		rot_rrb = INT_MAX - 1;
	if ((absolute(rot_rrb) + 1) < absolute(*rot))
	{
		rrb(b, 1);
		*rot = rot_rrb;
	}
}

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
	if (distance_ra < (int)(list_size(a) / 2))
		return (distance_ra);
	else
		return (distance_ra - (int)list_size(a));
}
