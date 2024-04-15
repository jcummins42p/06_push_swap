/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:41:07 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/15 18:07:00 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

//	Starting at i = 1 because the first element is non-malloc'd placeholder
void	argv_free(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	execute_cmd(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		pa(b, a);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	read_command(t_stack **a)
{
	t_stack	*b;
	size_t	read_size;
	size_t	final_size;
	char	cmd[5];

	b = NULL;
	final_size = list_size(a);
	while (1)
	{
		read_size = read(STDIN_FILENO, cmd, 4);
		if (read_size <= 0)
			break ;
		if (!execute_cmd(a, &b, cmd))
			write(2, "Error\n", 6);
		draw_stacks(a, &b);
	}
	if (read_size == 0)
	{
		if (check_sorted(a) && list_size(a) == final_size)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	list_clear(&b);
	list_clear(a);
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
		read_command(&a);
	else
		write(2, "Error\n", 6);
	if (free_flag)
		argv_free(argv);
	return (0);
}
