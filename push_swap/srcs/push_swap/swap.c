/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:41:55 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:41:59 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print_command)
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
	if (print_command)
		ft_printf("sa\n");
	fflush(stdout);
}

void	sb(t_stack **b, int print_command)
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
	if (print_command)
		ft_printf("sb\n");
	fflush(stdout);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
	fflush(stdout);
}
