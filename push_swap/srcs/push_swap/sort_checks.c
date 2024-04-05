/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:21:37 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/05 16:22:22 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_reverse(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr->next)
	{
		if (curr->val < curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_sorted(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}
