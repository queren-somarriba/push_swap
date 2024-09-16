/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:26:19 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/08 18:47:29 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_data_min(t_list **lst)
{
	t_list	*tmp;
	int		min;

	tmp = *lst;
	min = (*lst)->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	lst_data_max(t_list **lst)
{
	t_list	*tmp;
	int		max;

	tmp = *lst;
	max = (*lst)->data;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*lst_node_min(t_list **lst)
{
	t_list	*min;

	min = *lst;
	while (min)
	{
		if (min->data == lst_data_min(lst))
			return (min);
		min = min->next;
	}
	return (NULL);
}

t_list	*lst_node_max(t_list **lst)
{
	t_list	*max;

	max = *lst;
	while (max)
	{
		if (max->data == lst_data_max(lst))
			return (max);
		max = max->next;
	}
	return (NULL);
}

void	lst_setmediane(t_list **lst)
{
	t_list	*tmp;
	size_t	mediane;

	tmp = *lst;
	mediane = ft_lstsize(*lst) / 2;
	while (tmp)
	{
		if (ft_lstsize(*lst) % 2 == 0)
		{
			if (tmp->index < mediane)
				tmp->mediane = 0;
			else
				tmp->mediane = 1;
		}
		else if (ft_lstsize(*lst) % 2 == 1)
		{
			if (tmp->index < mediane + 1)
				tmp->mediane = 0;
			else
				tmp->mediane = 1;
		}
		tmp = tmp->next;
	}
}
