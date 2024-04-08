/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/08 18:36:45 by jcummins         ###   ########.fr       */
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
	if (direction < 0)
	{
		if ((*s)->val < (*s)->next->val && (*s)->val < (*s)->next->next->val)
			rb(s, 1);
		else if ((*s)->val < (*s)->next->val && \
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
	else
		ft_printf("direction arg neg for descending or pos for ascending\n");
}

void	final_sort(t_stack **a)
{
	int	rotate_by;

	rotate_by = 0;
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
