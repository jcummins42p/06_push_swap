/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:22:09 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 14:43:21 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_uniq(t_stack **a, int n)
{
	t_stack	*curr;

	if (*a == NULL)
		return (-1);
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

int	valid_in(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
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
