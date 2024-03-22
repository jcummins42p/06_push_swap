/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:25:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/22 11:41:52 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int	app_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*curr;

	curr = *a;
	node = malloc(sizeof(t_stack));
	if (node == NULL || a == NULL)
		return (0);
	node->val = n;
	node->next = NULL;
	if (curr == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		curr = last_node(a);
		curr->next = node;
		node->prev = curr;
	}
	return (1);
}

void	list_node(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	if (a == NULL || *a == NULL)
	{
		printf("Error: empty list pointer\n");
	}
	else
	{
		while (curr)
		{
			printf("Node: %p\t Value: %d\n", curr, curr->val);
			curr = curr->next;
		}
	}
}

void	stack_clear(t_stack **a)
{
	t_stack	*curr;
	t_stack	*swap;

	if (a == NULL || *a == NULL)
		return ;
	curr = *a;
	while (curr)
	{
		swap = curr;
		curr = curr->next;
		free(swap);
	}
	*a = NULL;
}

int	stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (valid_uniq(a, n) && valid_range(n))
			app_node(a, (int)n);
		else
		{
			printf("Invalid input\n");
			stack_clear(a);
			return (0);
		}
		i++;
	}
	return (1);
}
