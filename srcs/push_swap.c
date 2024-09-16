/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:34:08 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/08 18:48:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if (ft_lstsize(*lst) == 3)
	{
		if ((*lst)->next->next->data == lst_data_max(lst)
			&& (*lst)->data > (*lst)->next->data)
			sa(lst);
		else if ((*lst)->next->data == lst_data_max(lst)
			&& (*lst)->data > (*lst)->next->next->data)
			rra(lst);
		else if ((*lst)->data == lst_data_max(lst)
			&& (*lst)->next->data < (*lst)->next->next->data)
			ra(lst);
		else if ((*lst)->next->next->data != lst_data_max(lst))
		{
			sa(lst);
			if ((*lst)->data == lst_data_max(lst))
				ra(lst);
			else
				rra(lst);
		}
	}
}

void	lst_setdata(t_list **lst1, t_list **lst2)
{
	lst_setindex(lst1);
	lst_setindex(lst2);
	lst_setmediane(lst1);
	lst_setmediane(lst2);
	lst_settarget(lst1, lst2, 0);
	lst_settarget(lst1, lst2, 1);
	lst_setcost(lst1, lst2);
	lst_setcost(lst2, lst1);
}

void	sort_stack(t_list **lst, int mode)
{
	t_list	*min;

	min = *lst;
	while (min->data != lst_data_min(lst))
		min = min->next;
	while ((*lst)->data != min->data)
	{
		if (mode == 0)
		{
			if (min->mediane == 0)
				ra(lst);
			if (min->mediane == 1)
				rra(lst);
		}
		if (mode == 1)
		{
			if (min->mediane == 0)
				rb(lst);
			if (min->mediane == 1)
				rrb(lst);
		}
	}
}

void	push_swap(t_list **lst1, t_list **lst2)
{
	if (ft_lstsize(*lst1) == 2
		&& (*lst1)->data > (*lst1)->next->data)
		sa(lst1);
	else if (ft_lstsize(*lst1) == 3)
		sort_three(lst1);
	else
	{
		pb(lst1, lst2);
		pb(lst1, lst2);
		while (ft_lstsize(*lst1) > 3)
		{
			lst_setdata(lst1, lst2);
			set_node_pb(node_topush(lst1), lst1, lst2);
			pb(lst1, lst2);
		}
		sort_three(lst1);
		while (ft_lstsize(*lst2))
		{
			lst_setdata(lst1, lst2);
			set_node_pa(node_topush(lst2), lst1, lst2);
			pa(lst1, lst2);
		}
		lst_setmediane(lst1);
		sort_stack(lst1, 0);
	}
}

int	main(int ac, char **av)
{
	t_list	**lst1;
	t_list	**lst2;

	lst1 = NULL;
	lst2 = (t_list **)malloc(sizeof(t_list *));
	if (!lst2)
		return (1);
	*lst2 = NULL;
	if (ac == 2)
		lst1 = ft_split_stack(av[1]);
	if (ac > 2)
		lst1 = ft_pars_stack(av, 1);
	if (!lst1 || !*lst1)
		return (ft_free_lst(lst2), 0);
	if (check_sortstack(lst1) || ft_lstsize(*lst1) < 2)
		return (ft_free_lst(lst1), ft_free_lst(lst2), 0);
	if (lst1)
		push_swap(lst1, lst2);
	ft_free_lst(lst1);
	ft_free_lst(lst2);
	return (0);
}
