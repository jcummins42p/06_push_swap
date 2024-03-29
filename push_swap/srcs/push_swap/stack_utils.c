/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:25:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/25 16:36:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	new_node(t_stack **dst, int n)
{
	t_stack	*node;
	t_stack	*curr;

	curr = *dst;
	node = malloc(sizeof(t_stack));
	if (node == NULL || dst == NULL)
		return (0);
	node->val = n;
	node->next = NULL;
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
