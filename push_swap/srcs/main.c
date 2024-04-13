/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:41:07 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:57:41 by jcummins         ###   ########.fr       */
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

//	more efficient management for smaller stacks size 4 or 5
void	sort_small(t_stack **a, t_stack **b, int size)
{
	(void)size;
	pb(a, b);
	if (size == 5)
		pb(a, b);
	sort_three(a, 1);
	final_sort_b(b);
	sorted_to_a(a, b);
	final_sort_a(a);
}

//	picks the most effective algorithm according to the size of the stack
void	sort_options(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted(a))
		;
	else
	{
		if (list_size(a) <= 2)
			ra(a, 1);
		else if (list_size(a) == 3)
			sort_three(a, 1);
		else if (list_size(a) < 6)
			sort_small(a, &b, list_size(a));
		else
			select_insert(a, &b);
	}
	list_clear(a);
	list_clear(&b);
}

int	main(int argc, char **argv)
{
	int		free_flag;
	t_stack	*a;

	free_flag = 0;
	a = NULL;
	if (argv == NULL)
		return (1);
	if (argc < 2)
		return (1);
	if (argc == 2 && argv[1])
	{
		argv = ft_split(argv[1], ' ');
		if (argv)
		{
			argv[0] = "placeholder";
			free_flag = 1;
		}
	}
	if (argv && list_init(&a, &argv[1]))
		sort_options(&a);
	else
		write(2, "Error\n", 6);
	if (free_flag)
		argv_free(argv);
	return (0);
}
