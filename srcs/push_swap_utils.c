/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:22:08 by qsomarri          #+#    #+#             */
/*   Updated: 2024/08/16 17:04:04 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_loop(void (*f)(t_list **), t_list **lst, int index)
{
	int	i;

	i = -1;
	if (index > 0)
	{
		while (++i < index)
			f(lst);
	}
}

static void	rotate_stacks_pb(t_list *node, t_list **lst1, t_list **lst2)
{
	if (node->mediane == 0 && node->target->mediane == 1)
	{
		op_loop(ra, lst1, node->index);
		op_loop(rrb, lst2, ft_lstsize(*lst2) - node->target->index);
	}
	else if (node->mediane == 1 && node->target->mediane == 0)
	{
		op_loop(rra, lst1, ft_lstsize(*lst1) - node->index);
		op_loop(rb, lst2, node->target->index);
	}
}

void	set_node_pb(t_list *node, t_list **a, t_list **b)
{
	if (node->mediane == 0 && node->target->mediane == 0)
	{
		while ((*a)->data != node->data
			&& (*b)->data != node->target->data)
			rr(a, b);
		if (node->index > node->target->index)
			op_loop(ra, a, node->cost - ft_min_len(node, a, b));
		else if (node->index < node->target->index)
			op_loop(rb, b, node->cost - ft_min_len(node, a, b));
	}
	else if (node->mediane == 1 && node->target->mediane == 1)
	{
		while ((*a)->data != node->data
			&& (*b)->data != node->target->data)
			rrr(a, b);
		if (ft_lstsize(*a) - node->index < ft_lstsize(*b) - node->target->index)
			op_loop(rrb, b, node->cost - ft_min_len(node, a, b));
		else if ((ft_lstsize(*a) - node->index
				> ft_lstsize(*b) - node->target->index))
			op_loop(rra, a, node->cost - ft_min_len(node, a, b));
	}
	else
		rotate_stacks_pb(node, a, b);
}

static void	rotate_stacks_pa(t_list *node, t_list **lst1, t_list **lst2)
{
	if (node->mediane == 0 && node->target->mediane == 1)
	{
		op_loop(rb, lst2, node->index);
		op_loop(rra, lst1, ft_lstsize(*lst1) - node->target->index);
	}
	else if (node->mediane == 1 && node->target->mediane == 0)
	{
		op_loop(rrb, lst2, ft_lstsize(*lst2) - node->index);
		op_loop(ra, lst1, node->target->index);
	}
}

void	set_node_pa(t_list *node, t_list **a, t_list **b)
{
	int	min;

	min = ft_min_len(node, a, b);
	if (node->mediane == 0 && node->target->mediane == 0)
	{
		while ((*b)->data != node->data && (*a)->data != node->target->data)
			rr(a, b);
		if (node->index > node->target->index)
			op_loop(rb, b, node->cost - min);
		else if (node->index < node->target->index)
			op_loop(ra, a, node->cost - min);
	}
	else if (node->mediane == 1 && node->target->mediane == 1)
	{
		while ((*b)->data != node->data && (*a)->data != node->target->data)
			rrr(a, b);
		if (ft_lstsize(*b) - node->index < ft_lstsize(*a) - node->target->index)
			op_loop(rra, a, node->cost - min);
		else if ((ft_lstsize(*b) - node->index
				> ft_lstsize(*a) - node->target->index))
			op_loop(rrb, b, node->cost - min);
	}
	else
		rotate_stacks_pa(node, a, b);
}
