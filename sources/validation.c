/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:22:09 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 18:19:59 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_uniq(t_stack **a, int n)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->val == n)
			return (0);
		else
			curr = curr->next;
	}
	return (1);
}

int	valid_range(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	else
		return (1);
}

int	valid_numb(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!isnum(argv[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
