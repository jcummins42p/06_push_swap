/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:25:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 14:44:00 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*curr;

	curr = *a;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->val = n;
	node->next = NULL;
	if (curr == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = node;
		node->prev = curr;
	}
}

void	list_node(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		printf("Current node %p, value %d\n", curr, curr->val);
		curr = curr->next;
	}
}

void	stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			printf("Long %d: error number out of range\n", i);
		else
		{
			if (valid_uniq(a, n))
				app_node(a, (int)n);
			else
				printf("Long %d: error repeated number\n", i);
			i++;
		}
	}
	list_node(a);
	(void)a;
}
