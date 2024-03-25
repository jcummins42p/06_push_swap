/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:54 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/25 14:49:53 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*swap;

	if (*src)
	{
		swap = (*src)->next;
		if (*dst)
		{
			(*src)->next = *dst;
			(*dst)->prev = *src;
		}
		else
			(*src)->next = NULL;
		*dst = *src;
		*src = swap;
		if (*src)
			(*src)->prev = NULL;
	}
}
