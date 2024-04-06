/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:25:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/06 13:17:06 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_stack **s)
{
	t_stack	*curr;
	int		min;

	curr = *s;
	if (curr == NULL)
		return (0);
	min = curr->val;
	while (curr)
	{
		if (min > curr->val)
			min = curr->val;
		curr = curr->next;
	}
	return (min);
}

int	max_value(t_stack **s)
{
	t_stack	*curr;
	int		max;

	curr = *s;
	if (curr == NULL)
		return (0);
	max = curr->val;
	while (curr)
	{
		if (max < curr->val)
			max = curr->val;
		curr = curr->next;
	}
	return (max);
}

t_stack	*last_node(t_stack **dst)
{
	t_stack	*curr;

	curr = *dst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

size_t	list_size(t_stack **s)
{
	t_stack	*curr;
	size_t	i;

	curr = *s;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}