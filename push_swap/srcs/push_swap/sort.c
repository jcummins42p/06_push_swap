/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 13:47:14 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	finds the most efficient number of rotations and direction to place integer
//	in target stack in ascending order into list a
int	dir_ins_ascending(t_stack **a, int insert)
{
	int		distance_ra;
	int		distance_rra;
	int		target;
	t_stack *curr;

	curr = *a;
	target = min_value(a);
	distance_ra = 0;
	distance_rra = 0;
	if (insert > max_value(a))
	{
		target = min_value(a);
		while (curr->val != target)
		{
			distance_ra++;
			curr = curr->next;
		}
	}
	else
	{
		target = max_value(a);
		distance_ra = 0;
		while (curr && curr->val != min_value(a) && insert < curr->val)
		{
			curr = curr->next;
			distance_ra++;
		}
		while (curr && insert > curr->val)
		{
			target = curr->val;
			distance_ra++;
			curr = curr->next;
		}
		if (curr)
			target = curr->val;
	}
	distance_rra = list_size(a) - distance_ra;
	if (distance_rra > distance_ra)
		return (distance_ra);
	else
		return (0 - distance_rra);
}
//	finds the most efficient number of rotations and direction to place integer
//	in target stack in descending order into list b
int	dir_ins_descending(t_stack **b, int insert)
{
	int		distance_rb;
	int		distance_rrb;
	int		target;
	t_stack *curr;

	curr = *b;
	target = max_value(b);
	distance_rb = 0;
	distance_rrb = 0;
	if (insert < min_value(b))
	{
		target = max_value(b);
		while (curr->val != target)
		{
			distance_rb++;
			curr = curr->next;
		}
	}
	else
	{
		target = min_value(b);
		distance_rb = 0;
		while (curr && curr->val != max_value(b) && insert > curr->val)
		{
			curr = curr->next;
			distance_rb++;
		}
		while (curr && insert < curr->val)
		{
			target = curr->val;
			distance_rb++;
			curr = curr->next;
		}
		if (curr)
			target = curr->val;
	}
	distance_rrb = list_size(b) - distance_rb;
	if (distance_rrb > distance_rb)
		return (distance_rb);
	else
		return (0 - distance_rrb);
}

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

void	sort_three_desc_b(t_stack **s)
{
	if ((*s)->val < (*s)->next->val && (*s)->val < (*s)->next->next->val)
		rb(s, 1);
	else if ((*s)->val < (*s)->next->val && \
			(*s)->next->next->val > (*s)->next->val)
		rrb(s, 1);
	if ((*s)->val < (*s)->next->val)
		sb(s, 1);
}

void	sort_three_asc_a(t_stack **s)
{
	if ((*s)->val > (*s)->next->val && (*s)->val > (*s)->next->next->val)
		ra(s, 1);
	else if ((*s)->val < (*s)->next->val && \
			(*s)->next->next->val < (*s)->next->val)
		rra(s, 1);
	if ((*s)->val > (*s)->next->val)
		sa(s, 1);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted(a))
		/*ft_printf("\nInput already sorted.\n")*/;
	else
	{
		/*slow_sort(a, &b);*/
		/*med_sort(a, &b);*/
		mirror_sort(a, &b);
	}
	/*draw_stacks(a, &b);*/
	/*if (check_sorted(a))*/
		/*ft_printf("List Sorted\n");*/
	list_clear(a);
	list_clear(&b);
}
