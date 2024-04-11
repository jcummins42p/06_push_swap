/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:31 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/11 16:24:17 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	find_costs(t_stack **a, t_stack **b)*/
/*{*/
	/*t_stack	*curr;*/

	/*curr = *b;*/
	/*while (curr)*/
	/*{*/

	/*}*/
/*}*/

void	set_targets(t_stack **a, t_stack **b)
{
	t_stack *curr;

	curr = *b;
	while (curr)
	{
		curr->target = target_asc(a, curr->val, min_v(a), max_v(a));
		curr = curr->next;
	}
}

void	set_indices(t_stack **a, t_stack **b)
{
	t_stack 		*curr;
	unsigned int	i;

	curr = *a;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
	curr = *b;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

void	select_insert(t_stack **a, t_stack **b)
{
	populate_b(a, b, 3);
	sort_three(a, 1);
	set_indices(a, b);
	set_targets(a, b);
	draw_targets(a, b);
}
