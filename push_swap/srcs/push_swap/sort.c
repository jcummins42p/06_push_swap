/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/28 14:02:47 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_b(t_stack **a, t_stack **b, int remain)
{
	int	i;

	i = 0;
	i = list_size(a);
	while (i > remain)
	{
		push(a, b);
		i--;
	}
}

void	swap_stacks(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted(a))
		ft_printf("\nInput already sorted.\n");
	else if (check_reverse(a))
	{
		ft_printf("\nInput reverse sorted.\n");
		populate_b(a, &b, 0);
		swap_stacks(a, &b);
	}
	else
		populate_b(a, &b, 3);
	draw_stacks(a, &b);
	list_clear(a);
	list_clear(&b);
}
