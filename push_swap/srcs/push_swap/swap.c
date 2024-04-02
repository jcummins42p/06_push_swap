/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:54 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/02 18:52:16 by jcummins         ###   ########.fr       */
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
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sa(b, 0);
	ft_printf("ss\n");
}
