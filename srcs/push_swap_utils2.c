/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:30:37 by qsomarri          #+#    #+#             */
/*   Updated: 2024/08/14 16:30:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*node_topush(t_list **lst)
{
	t_list	*tmp;
	t_list	*node;

	tmp = *lst;
	node = *lst;
	while (tmp)
	{
		if (tmp->cost < node->cost)
			node = tmp;
		tmp = tmp->next;
	}
	return (node);
}
