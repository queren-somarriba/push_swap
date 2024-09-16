/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:38:05 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/14 15:40:18 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstlast_prev(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

void	lst_setindex(t_list **lst)
{
	t_list	*tmp;
	size_t	index;

	tmp = *lst;
	index = 0;
	if (lst)
	{
		while (tmp)
		{
			tmp->index = index++;
			tmp = tmp->next;
		}
	}
}

void	ft_free_lst(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				tmp = *lst;
				*lst = (*lst)->next;
				free(tmp);
			}
		}
		free(lst);
	}
}
