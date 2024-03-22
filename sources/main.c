/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:09:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/21 18:43:56 by jcummins         ###   ########.fr       */
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

void	array_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	main(int argc, char **argv)
{
	int		free_flag;
	t_stack	*a;
	//t_stack	*b;

	free_flag = 0;
	a = NULL;
	if (argv == NULL)
		return (1);
	if (argc == 2 && argv[1])
	{
		free_flag = 1;
		argv = ft_split(argv[1], ' ');
	}
	if (valid_numb(argv))
		stack_init(&a, &argv[1]);
	else
		printf("error, non number argument passed\n");
	list_node(&a);
	stack_clear(&a);
	if (free_flag)
		array_free(argv);
	return (0);
}
