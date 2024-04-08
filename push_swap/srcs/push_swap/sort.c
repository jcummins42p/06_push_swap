/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:33:34 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/08 12:42:52 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	A function that takes the target stack, the number to insert, and the des-
//	ired orientation of sort (positive number for ascending, neg fro descending
int	insert_direction(t_stack **a, int insert, int orient)
{
	int		distance_ra;
	int		target;
	t_stack	*curr;

	curr = *a;
	if (orient > 0)
		target = min_value(a);
	else if (orient < 0)
		target = max_value(a);
	distance_ra = 0;
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
	if (distance_ra < (int)(list_size(a) / 2))
		return (distance_ra);
	else
		return (distance_ra - (int)list_size(a));
}

//	finds the most efficient number of rotations and direction to place integer
//	in target stack in ascending order into list a
int	dir_ins_ascending(t_stack **a, int insert)
{
	int		distance_ra;
	int		target;
	t_stack	*curr;

	curr = *a;
	target = min_value(a);
	distance_ra = 0;
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
	if (distance_ra < (int)(list_size(a) / 2))
		return (distance_ra);
	else
		return (distance_ra - (int)list_size(a));
}

//	finds the most efficient number of rotations and direction to place integer
//	in target stack in descending order into list b
int	dir_ins_descending(t_stack **b, int insert)
{
	int		distance_rb;
	int		target;
	t_stack	*curr;

	curr = *b;
	target = max_value(b);
	distance_rb = 0;
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
	if (distance_rb < (int)(list_size(b) / 2))
		return (distance_rb);
	else
		return (distance_rb - (int)list_size(b));
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

void	sort_three(t_stack **s, int direction)
{
	if (direction < 0)
	{
		if ((*s)->val < (*s)->next->val && (*s)->val < (*s)->next->next->val)
			rb(s, 1);
		else if ((*s)->val < (*s)->next->val && \
				(*s)->next->next->val > (*s)->next->val)
			rrb(s, 1);
		if ((*s)->val < (*s)->next->val)
			sb(s, 1);
	}
	else if (direction > 0)
	{
		if ((*s)->val > (*s)->next->val && (*s)->val > (*s)->next->next->val)
			ra(s, 1);
		else if ((*s)->val < (*s)->next->val && \
				(*s)->next->next->val < (*s)->next->val)
			rra(s, 1);
		if ((*s)->val > (*s)->next->val)
			sa(s, 1);
	}
	else
		ft_printf("direction arg neg for descending or pos for ascending\n");
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted(a))
		;
	else
	{
		/*slow_sort(a, &b);*/
		/*med_sort(a, &b);*/
		mirror_sort(a, &b);
	}
	/*draw_stacks(a, &b);*/
	list_clear(a);
	list_clear(&b);
}
