/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:41:05 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/26 20:20:51 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		col_a = draw_by_index(a, (height - i));
		col_b = draw_by_index(b, (height - i));
		if (i == height)
			ft_printf("HEAD ->");
		ft_printf("\t%s\t\t%s\n",
			col_a, col_b);
		i++;
		free(col_a);
		free(col_b);
	}
	ft_printf("\t~~~~~~~\t\t\t~~~~~~~\n");
	ft_printf("\tStack A\t\t\tStack B\n\n");
}

char	*draw_by_index(t_stack **s, size_t index)
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
