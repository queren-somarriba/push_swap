/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:01 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/08 18:21:42 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lst_compute_cost(t_list *node, t_list **lst1, t_list **lst2)
{
	int	node_cost;
	int	target_cost;

	node_cost = 0;
	target_cost = 0;
	if (node->mediane == 0)
		node_cost = node->index;
	else
		node_cost = ft_lstsize(*lst1) - node->index;
	if (node->target->mediane == 0)
		target_cost = node->target->index;
	else
		target_cost = ft_lstsize(*lst2) - node->target->index;
	if (node->mediane == node->target->mediane)
		return (ft_max(node_cost, target_cost));
	else
		return (node_cost + target_cost);
}

void	lst_setcost(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	tmp = *lst1;
	while (tmp)
	{
		tmp->cost = lst_compute_cost(tmp, lst1, lst2);
		tmp = tmp->next;
	}
}

static t_list	*compute_target_stack_a(t_list *node, t_list **lst)
{
	t_list	*tmp;
	t_list	*target;

	tmp = *lst;
	target = lst_node_min(lst);
	if (node->data < lst_data_min(lst))
	{
		while (tmp)
		{
			if (tmp->data == lst_data_max(lst))
				return (tmp);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (tmp->data < node->data && tmp->data > target->data)
				target = tmp;
			tmp = tmp->next;
		}
	}
	return (target);
}

static t_list	*compute_target_stack_b(t_list	*node, t_list **lst)
{
	t_list	*tmp;
	t_list	*target;

	tmp = *lst;
	target = lst_node_max(lst);
	if (node->data > lst_data_max(lst))
	{
		while (tmp)
		{
			if (tmp->data == lst_data_min(lst))
				return (tmp);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (tmp->data > node->data && tmp->data < target->data)
				target = tmp;
			tmp = tmp->next;
		}
	}
	return (target);
}

void	lst_settarget(t_list **lst1, t_list **lst2, int mode)
{
	t_list	*tmp;

	tmp = NULL;
	if (mode == 0)
		tmp = *lst1;
	else
		tmp = *lst2;
	while (tmp)
	{
		if (mode == 0)
			tmp->target = compute_target_stack_a(tmp, lst2);
		else
			tmp->target = compute_target_stack_b(tmp, lst1);
		tmp = tmp->next;
	}
}
