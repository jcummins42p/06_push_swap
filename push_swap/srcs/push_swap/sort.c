/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/06 21:53:27 by jcummins         ###   ########.fr       */
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
		pb(a, b);
		i--;
	}
}

void	sort_three(t_stack **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
		ra(a, 1);
	else if ((*a)->val < (*a)->next->val && \
			(*a)->next->next->val < (*a)->next->val)
		rra(a, 1);
	if ((*a)->val > (*a)->next->val)
		sa(a, 1);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted(a))
		/*ft_printf("\nInput already sorted.\n")*/;
	else
	{
		/*draw_stacks(a, &b);*/
		populate_b(a, &b, 3);
		/*draw_stacks(a, &b);*/
		sort_three(a);
		/*draw_stacks(a, &b);*/
		med_sort(a, &b);
		/*slow_sort(a, &b);*/
	}
	/*draw_stacks(a, &b);*/
	/*if (check_sorted(a))*/
		/*ft_printf("List Sorted\n");*/
	list_clear(a);
	list_clear(&b);
}
