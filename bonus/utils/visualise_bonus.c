/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:46:52 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 17:42:48 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
		ft_printf("\t%s\t%s\n",
			col_a, col_b);
		i++;
		free(col_a);
		free(col_b);
	}
	ft_printf("\t~~~A~~~\t\t~~~B~~~\n");
}
