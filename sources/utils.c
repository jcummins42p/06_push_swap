/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:18 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 18:24:56 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
