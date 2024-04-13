/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:46:40 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:46:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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

long int	ft_atol(char const *str)
{
	long	out;
	int		i;
	int		neg;

	if (!str)
		return (0);
	out = 0;
	i = 0;
	neg = 1;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && isnum(str[i]))
	{
		out *= 10;
		out += ((str[i]) - '0');
		i++;
	}
	return (out * neg);
}

int	valid_numb(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (argv[i][j])
			{
				if (isnum(argv[i][j]))
					j++;
				else
					return (0);
			}
			if (argv[i][j - 1] == '-' || argv[i][j - 1] == '+')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
