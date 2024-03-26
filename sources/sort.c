/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/26 18:42:12 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_b(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	i = list_size(a);
	while (i > 3)
	{
		push(a, b);
		i--;
	}
}

int	check_sorted(t_stack **a)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *a;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void ft_sort(t_stack **a)
{
	t_stack *b;

	b = NULL;
	if (check_sorted(a))
		printf("\nInput already sorted. nothing to change\n");
	populate_b(a, &b);
	/*rr(a, &b);*/
	draw_stacks(a, &b);
	list_clear(a);
	list_clear(&b);
}
