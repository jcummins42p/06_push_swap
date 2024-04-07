/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:24 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/07 18:31:20 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	populate_b(t_stack **a, t_stack **b, int remain)*/
/*{*/
	/*int	i;*/

	/*i = 0;*/
	/*i = list_size(a);*/
	/*while (i > remain)*/
	/*{*/
		/*pb(a, b);*/
		/*i--;*/
	/*}*/
/*}*/

void	populate_b_desc(t_stack **a, t_stack **b, int remain)
{
	int		last_val;
	int		stack_a_size;
	int		rotated;

	rotated = 0;
	stack_a_size = list_size(a);
	last_val = INT_MAX;
	while (stack_a_size > remain)
	{
		if ((*a)->val < last_val)
		{
			pb(a, b);
			last_val = (*b)->val;
			stack_a_size--;
			rotated = 0;
		}
		else
		{
			ra(a, 1);
			rotated++;
			if (rotated >= stack_a_size)
				break;
		}
	}
}
