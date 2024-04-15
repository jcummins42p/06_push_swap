/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:44:38 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:44:42 by jcummins         ###   ########.fr       */
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
