/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:49:40 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/08 19:20:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_rx_to_min(t_stack **s, int max_s)
{
	int		distance_rs;
	t_stack	*curr;

	distance_rs = 0;
	curr = *s;
	while (curr->val != max_s)
	{
		distance_rs++;
		curr = curr->next;
	}
	return (distance_rs);
}

//	cheap_neighbour takes a look at the insertion cost of the two values in b
//	are only one rotation away, rotates b to put them at the head of the stack,
//	and updates the rot variable with the new value and direction to the target.
void	cheap_neighbour_desc(t_stack **a, t_stack **b, int *rot)
{
	int	rot_rb;
	int	rot_rrb;

	rot_rb = cost_desc(a, (*b)->next->val, min_v(a), max_v(a));
	if ((absolute(rot_rb) + 1) < absolute(*rot))
	{
		rb(b, 1);
		*rot = rot_rb;
	}
	rot_rrb = cost_desc(a, last_node(b)->val, min_v(a), max_v(a));
	if ((absolute(rot_rrb) + 1) < absolute(*rot))
	{
		rrb(b, 1);
		*rot = rot_rrb;
	}
}

//	finds the most efficient number of rotations and direction to place integer
//	in target stack in descending order into list b
int	cost_desc(t_stack **b, int insert, int min_b, int max_b)
{
	int		distance_rb;
	t_stack	*curr;

	curr = *b;
	distance_rb = 0;
	if (insert < min_b)
		distance_rb = n_rx_to_min(b, max_b);
	else
	{
		while (curr && curr->val != max_b && insert > curr->val)
		{
			curr = curr->next;
			distance_rb++;
		}
		while (curr && insert < curr->val)
		{
			curr = curr->next;
			distance_rb++;
		}
	}
	if (distance_rb < (int)(list_size(b) / 2))
		return (distance_rb);
	else
		return (distance_rb - (int)list_size(b));
}
