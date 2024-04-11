/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:30:28 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/11 18:05:53 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	putting back the sorted numbers from b to a doesn't require the nearest
//	neighbour function - this can result in global optimi suffering for small
//	local efficiencies.
void	sorted_to_a(t_stack **a, t_stack **b)
{
	int	rot;

	while (*b)
	{
		rot = cost_asc(a, (*b)->val, min_v(a), max_v(a));
		if (rot > 0)
			while (rot-- > 0)
				ra(a, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rra(a, 1);
		pa(b, a);
	}
}

//	sorting the the unordered part of the list back into a, checking to avoid
//	eating into the sorted list with the use of sentry values.
void	sort_into_a(t_stack **a, t_stack **b)
{
	int	rot;

	while (*b && list_size(b) > list_size(a))
	{
		if ((*b)->sentry_min)
		{
			rb(b, 1);
			rb(b, 1);
		}
		else if ((*b)->sentry_max)
		{
			rrb(b, 1);
			rrb(b, 1);
		}
		rot = cost_asc(a, (*b)->val, min_v(a), max_v(a));
		if ((*b)->next)
			cheap_neighbour_asc(a, b, &rot);
		if (rot > 0)
			while (rot-- > 0)
				ra(a, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rra(a, 1);
		pa(b, a);
	}
}

//	sorts half of a into b in descending order, then flags the start and end
//	of this so that they are not sorted back into a before unsorted values
void	sort_into_b(t_stack **a, t_stack **b)
{
	int	rot;
	int	half_a;
	int	i;

	i = 0;
	half_a = (list_size(a) / 2) - 1;
	while (i < half_a)
	{
		rot = cost_desc(b, (*a)->val, min_v(b), max_v(b));
		if ((*a)->next)
			cheap_neighbour_desc(a, b, &rot);
		if (rot > 0)
			while (rot-- > 0)
				rb(b, 1);
		else if (rot < 0)
			while (rot++ < 0)
				rrb(b, 1);
		pb(a, b);
		i++;
	}
	find_node(b, min_v(b))->sentry_min = ft_itoa(min_v(b));
	find_node(b, max_v(b))->sentry_max = ft_itoa(max_v(b));
}

void	free_sentry(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->sentry_min)
			free(curr->sentry_min);
		if (curr->sentry_max)
			free(curr->sentry_max);
		curr = curr->next;
	}
	curr = *b;
	while (curr)
	{
		if (curr->sentry_min)
			free(curr->sentry_min);
		if (curr->sentry_max)
			free(curr->sentry_max);
		curr = curr->next;
	}
}

void	mirror_insert(t_stack **a, t_stack **b)
{
	populate_b(a, b, list_size(a) - 3);
	sort_three(b, -1);
	sort_into_b(a, b);
	final_sort_b(b);
	populate_b(a, b, 3);
	sort_three(a, 1);
	sort_into_a(a, b);
	final_sort_a(a);
	sorted_to_a(a, b);
	final_sort_a(a);
}
