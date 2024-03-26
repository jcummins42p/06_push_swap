/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:54 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/26 20:46:49 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **src)
{
	t_stack	*first;
	t_stack	*second;

	if (*src && (*src)->next)
	{
		first = (*src);
		second = (*src)->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*src = second;
	}
}
