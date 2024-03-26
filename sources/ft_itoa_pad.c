/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:45 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/26 18:20:44 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_digits(unsigned int n)
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

unsigned int	absolute(int n)
{
	unsigned int	abs;

	abs = 0;
	if (n < 0)
		abs = -n;
	else
		abs = n;
	return (abs);
}

char	*printstr_pad(char *s, unsigned int n, int neg, int pad)
{
	int	i;

	i = (n_digits(n));
	if (pad > i)
	{
		s[pad--] = '\0';
		while (pad > i)
			s[pad--] = ' ';
	}
	else
		s[i + neg] = '\0';
	while (i > 0)
	{
		s[i] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	if (neg)
		s[0] = '-';
	else
		s[0] = ' ';
	return (s);
}

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

char	*ft_itoa_pad(int n, int pad)
{
	char			*str;
	int				neg;
	unsigned int	num;
	int				size;

	neg = 0;
	if (n < 0)
		neg = 1;
	num = absolute(n);
	size = n_digits(num) + 1 + neg;
	if (size < pad)
		size = pad;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	printstr_pad(str, num, neg, pad);
	return (str);
}

/*int	main(void)*/
/*{*/
	/*int	i;*/

	/*i = -2147483648;*/
	/*printf("The number %d as a string is %s\n", i, ft_itoa(i));*/
	/*return (0);*/
/*}*/
