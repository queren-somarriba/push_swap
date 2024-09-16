/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:10:04 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/14 16:56:50 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_cmd_list(char *str)
{
	if (!str)
		return (-1);
	if (ft_strncmp(str, "pa\n", ft_strlen(str))
		&& ft_strncmp(str, "pb\n", ft_strlen(str))
		&& ft_strncmp(str, "ra\n", ft_strlen(str))
		&& ft_strncmp(str, "rb\n", ft_strlen(str))
		&& ft_strncmp(str, "rr\n", ft_strlen(str))
		&& ft_strncmp(str, "rra\n", ft_strlen(str))
		&& ft_strncmp(str, "rrb\n", ft_strlen(str))
		&& ft_strncmp(str, "rrr\n", ft_strlen(str))
		&& ft_strncmp(str, "sa\n", ft_strlen(str))
		&& ft_strncmp(str, "sb\n", ft_strlen(str)))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

static void	execute_commands2(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate_stack(stack_a);
	if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate_stack(stack_b);
	if (!ft_strncmp(str, "rrr\n", 4))
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_b);
	}
}

void	execute_commands(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_stack(stack_a);
	if (!ft_strncmp(str, "sb\n", 3))
		swap_stack(stack_b);
	if (!ft_strncmp(str, "ss\n", 3))
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	if (!ft_strncmp(str, "pa\n", 3))
	{
		push_stack(stack_b, stack_a);
	}
	if (!ft_strncmp(str, "pb\n", 3))
		push_stack(stack_a, stack_b);
	if (!ft_strncmp(str, "ra\n", 3))
		rotate_stack(stack_a);
	if (!ft_strncmp(str, "rb\n", 3))
		rotate_stack(stack_b);
	if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
	execute_commands2(str, stack_a, stack_b);
}

int	checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	if (check_cmd_list(line))
		return (free(line), -1);
	while (line)
	{
		execute_commands(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
		if (check_cmd_list(line) == 1)
			return (free(line), -1);
	}
	if (check_sortstack(stack_a) == 1 && !ft_lstsize(*stack_b))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_list	**stack;
	t_list	**stack2;
	int		res;

	stack = NULL;
	stack2 = (t_list **)malloc(sizeof(t_list *));
	if (!stack2)
		return (0);
	*stack2 = NULL;
	if (argc == 2)
		stack = ft_split_stack(argv[1]);
	if (argc > 2)
		stack = ft_pars_stack(argv, 1);
	if (!stack)
		return (ft_free_lst(stack), free(stack2), 0);
	if (ft_lstsize(*stack) < 2 || check_sortstack(stack))
		return (ft_free_lst(stack), free(stack2), ft_putstr_fd("OK\n", 1), 0);
	res = checker(stack, stack2);
	if (res == -1)
		return (ft_free_lst(stack), ft_free_lst(stack2), 0);
	if (!res)
		ft_putstr_fd("KO\n", 1);
	if (res == 1)
		ft_putstr_fd("OK\n", 1);
	return (ft_free_lst(stack), ft_free_lst(stack2), 0);
}
