/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:46:01 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:46:03 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_digits(unsigned int n)
{
	unsigned int	digits;

	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	abs;

	abs = 0;
	if (n < 0)
		abs = -n;
	else
		abs = n;
	return (abs);
}

static char	*printstr(char *s, unsigned int n, int neg)
{
	int	i;

	i = (n_digits(n));
	s[i-- + neg] = '\0';
	while (i >= 0)
	{
		s[i + neg] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				neg;
	unsigned int	num;

	neg = 0;
	if (n < 0)
		neg = 1;
	num = ft_abs(n);
	str = (char *)malloc((n_digits(num) + 1 + neg) * sizeof(char));
	if (!str)
		return (NULL);
	printstr(str, num, neg);
	return (str);
}
