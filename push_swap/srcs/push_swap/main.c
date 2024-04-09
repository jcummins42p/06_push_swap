/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:09:10 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/09 17:20:30 by jcummins         ###   ########.fr       */
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

//	more efficient management for smaller stacks
void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 4)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
		insort_to_b(a, b);
	}
	if (size == 3)
		sort_three(a, 1);
	insort_to_a(a, b);
	final_sort_a(a);
}

void	ft_sort(t_stack **a)
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
		else if (list_size(a) < 7)
			sort_small(a, &b, list_size(a));
		else
			mirror_insert(a, &b);
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
	if (argc == 2 && argv[1])
	{
		free_flag = 1;
		argv = ft_split(argv[1], ' ');
	}
	if (!list_init(&a, &argv[1]))
		write(2, "Error\n", 6);
	else
		ft_sort(&a);
	if (free_flag)
		argv_free(argv);
	return (0);
}
