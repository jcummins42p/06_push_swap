/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:09:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/20 17:12:25 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_print(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%d: %s\n", i, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argv == NULL)
		return (1);
	if (argc == 2 && argv[1])
		argv = ft_split(argv[1], ' ');
	if (valid_in(argv))
	{
		//argv_print(argv);
		stack_init(&a, &argv[1]);
	}
	else
		printf("error, non number argument passed\n");
	return (0);
}
