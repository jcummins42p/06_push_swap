/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:41:05 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/12 17:16:16 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*empty_pad(int pad)
{
	char	*str;

	str = (char *)malloc((pad) * sizeof(char));
	if (!str)
		return (NULL);
	str[--pad] = '\0';
	while (pad-- > 0)
		str[pad] = ' ';
	return (str);
}

char	*draw_target_by_index(t_stack **s, size_t index)
{
	t_stack	*curr;
	size_t	i;
	char	*out;

	i = 0;
	curr = *s;
	out = NULL;
	while (curr)
	{
		if (i++ == index)
			out = ft_itoa(curr->target);
		curr = curr->next;
	}
	return (out);
}

char	*draw_value_by_index(t_stack **s, size_t index)
{
	t_stack	*curr;
	size_t	i;
	char	*out;
	int		pad;

	i = 0;
	curr = *s;
	out = NULL;
	pad = 12;
	while (curr)
	{
		if (i++ == index)
			out = ft_itoa_pad(curr->val, pad);
		curr = curr->next;
	}
	if (!out)
		out = empty_pad(pad);
	return (out);
}

char	*draw_cost_by_index(t_stack **s, size_t index)
{
	t_stack	*curr;
	size_t	i;
	char	*out;

	i = 0;
	curr = *s;
	out = NULL;
	while (curr)
	{
		if (i++ == index)
			out = ft_itoa(curr->cost);
		curr = curr->next;
	}
	return (out);
}

void	draw_targets(t_stack **a, t_stack **b)
{
	size_t	height;
	size_t	i;
	char	*col_a;
	char	*col_b;
	char	*b_target;
	char	*b_cost;

	i = 1;
	height = list_size(a);
	if (height <= list_size(b))
		height = list_size(b);
	ft_printf("\n");
	while (i <= height)
	{
		col_a = draw_value_by_index(a, (height - i));
		col_b = draw_value_by_index(b, (height - i));
		b_target = draw_target_by_index(b, (height - i));
		b_cost = draw_cost_by_index(b, (height - i));
		ft_printf("\t%s\t%s (target: %s, cost: %s)\n",
			col_a, col_b, b_target, b_cost);
		i++;
		free(col_a);
		free(col_b);
		free(b_target);
		free(b_cost);
	}
	ft_printf("\t~~~A~~~\t\t~~~B~~~\n");
}

void	draw_stacks(t_stack **a, t_stack **b)
{
	size_t	height;
	size_t	i;
	char	*col_a;
	char	*col_b;

	i = 1;
	height = list_size(a);
	if (height <= list_size(b))
		height = list_size(b);
	ft_printf("\n");
	while (i <= height)
	{
		col_a = draw_value_by_index(a, (height - i));
		col_b = draw_value_by_index(b, (height - i));
		if (i == height)
			ft_printf("HEAD ->");
		ft_printf("\t%s\t\t%s\n",
			col_a, col_b);
		i++;
		free(col_a);
		free(col_b);
	}
	ft_printf("\t~~~A~~~\t\t\t~~~B~~~\n");
}
