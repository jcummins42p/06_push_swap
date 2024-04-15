/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cformats_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:40:01 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 15:47:13 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i = print_str("(null)");
	else
		while (str[i])
			write (1, &str[i++], 1);
	return (i);
}

int	print_char(char chr)
{
	write (1, &chr, 1);
	return (1);
}
