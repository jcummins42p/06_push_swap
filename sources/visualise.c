/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:41:05 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/25 16:36:36 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_stacks(t_stack **a, t_stack **b)
{
	size_t	len_a;
	size_t	len_b;
	size_t	height;
	size_t	i;

	i = 1;
	len_a = list_size(a);
	len_b = list_size(b);
	if (len_a >= len_b)
		height = len_a;
	else
		height = len_b;
	printf("\n");
	while (i <= height)
	{
		if (i == height)
			printf("HEAD ->");
		printf("\t%ld\t\t\t%ld\n",
			get_by_index(a, (height - i)), get_by_index(b, (height - i)));
		i++;
	}
	printf("\t~~~~~~~\t\t\t~~~~~~~\n");
	printf("\tStack A\t\t\tStack B\n\n");
}

size_t	get_by_index(t_stack **s, size_t index)
{
	t_stack	*curr;
	size_t	i;

	i = 0;
	curr = *s;
	while (curr)
	{
		if (i++ == index)
			return (curr->val);
		curr = curr->next;
	}
	return (0);
}

void	list_print(t_stack **dst)
{
	t_stack	*curr;

	curr = *dst;
	if (dst == NULL || *dst == NULL)
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
