/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:45:30 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:45:31 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_stack *node, int val)
{
	node->val = val;
	node->target = INT_MAX;
	node->index = UINT_MAX;
	node->cost = UINT_MAX;
	node->sentry_min = NULL;
	node->sentry_max = NULL;
}

int	new_node(t_stack **dst, int val)
{
	t_stack	*node;
	t_stack	*curr;

	curr = *dst;
	node = malloc(sizeof(t_stack));
	if (node == NULL || dst == NULL)
		return (0);
	node->next = NULL;
	init_node(node, val);
	if (curr == NULL)
	{
		*dst = node;
		node->prev = NULL;
	}
	else
	{
		curr = last_node(dst);
		curr->next = node;
		node->prev = curr;
	}
	return (1);
}

void	list_clear(t_stack **dst)
{
	t_stack	*curr;
	t_stack	*swap;

	if (dst == NULL || *dst == NULL)
		return ;
	curr = *dst;
	while (curr)
	{
		swap = curr;
		curr = curr->next;
		free(swap);
	}
	*dst = NULL;
}

int	list_init(t_stack **dst, char **argv)
{
	long	n;
	int		i;

	i = 0;
	if (!argv || !*argv)
		return (0);
	if (!valid_numb(argv))
		return (0);
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (valid_uniq(dst, n) && valid_range(n))
			new_node(dst, (int)n);
		else
			return (0);
		i++;
	}
	return (1);
}
