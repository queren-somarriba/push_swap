/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:10:49 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/13 14:53:03 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(*lst) > 1)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	rotate_stack(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_lstlast(*lst)->next = tmp;
	}
}

void	reverse_rotate_stack(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(*lst) > 1)
	{
		tmp = ft_lstlast(*lst);
		ft_lstlast_prev(*lst)->next = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	push_stack(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	tmp = NULL;
	if (*lst1 && ft_lstsize(*lst1) > 0)
	{
		tmp = *lst1;
		*lst1 = (*lst1)->next;
		tmp->next = *lst2;
		*lst2 = tmp;
	}
}

void	rrr(t_list **lst1, t_list **lst2)
{
	reverse_rotate_stack(lst1);
	reverse_rotate_stack(lst2);
	ft_printf("rrr\n");
}
