/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:41:55 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 16:22:59 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a && (*a)->next)
	{
		first = (*a);
		second = (*a)->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*a = second;
	}
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b && (*b)->next)
	{
		first = (*b);
		second = (*b)->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*b = second;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
