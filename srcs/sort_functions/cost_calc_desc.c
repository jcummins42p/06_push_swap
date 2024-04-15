/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:43:11 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:43:14 by jcummins         ###   ########.fr       */
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

//	finds alternative neighbouring values in a that would be more efficient to
//	insert to b
void	cheap_neighbour_desc(t_stack **a, t_stack **b, int *rot)
{
	int	rot_ra;
	int	rot_rra;

	rot_ra = cost_desc(b, (*a)->next->val, min_v(b), max_v(b));
	if ((absolute(rot_ra) + 1) < absolute(*rot))
	{
		ra(a, 1);
		*rot = rot_ra;
	}
	rot_rra = cost_desc(b, last_node(a)->val, min_v(b), max_v(b));
	if ((absolute(rot_rra) + 1) < absolute(*rot))
	{
		rra(a, 1);
		*rot = rot_rra;
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
