/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:09:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/03/25 16:44:42 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	Starting at i = 1 because the first element is non-malloc'd placeholder
void	argv_free(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	main(int argc, char **argv)
{
	int		free_flag;
	t_stack	*a;
	t_stack	*b;

	free_flag = 0;
	a = NULL;
	b = NULL;
	if (argv == NULL)
		return (1);
	if (argc == 2 && argv[1])
	{
		free_flag = 1;
		argv = ft_split(argv[1], ' ');
	}
	if (!list_init(&a, &argv[1]))
		printf("error, non number argument passed\n");
	else
	{
		push(&a, &b);
		push(&a, &b);
		push(&a, &b);
		/*rr(&a, &b);*/
		/*list_print(&a);*/
		/*list_print(&b);*/
		draw_stacks(&a, &b);
	}
	list_clear(&a);
	list_clear(&b);
	if (free_flag)
		argv_free(argv);
	return (0);
}
