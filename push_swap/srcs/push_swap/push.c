/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:54 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/05 19:34:44 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*swap;

	if (*b)
	{
		swap = (*b)->next;
		if (*a)
		{
			(*b)->next = *a;
			(*a)->prev = *b;
		}
		else
			(*b)->next = NULL;
		*a = *b;
		*b = swap;
		if (*b)
			(*b)->prev = NULL;
	}
	printf("pa\n");
	fflush(stdout);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	if (*a)
	{
		swap = (*a)->next;
		if (*b)
		{
			(*a)->next = *b;
			(*b)->prev = *a;
		}
		else
			(*a)->next = NULL;
		*b = *a;
		*a = swap;
		if (*a)
			(*a)->prev = NULL;
	}
	printf("pb\n");
	fflush(stdout);
}
