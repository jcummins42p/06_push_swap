/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:32:05 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/20 17:04:20 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
//
//int	main(void)
//{
//	printf("String: %s\nLong: %ld\n", "-12f34", ft_atol("-12f34"));
//	return (0);
//}
