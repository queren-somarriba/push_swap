/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:46:18 by qsomarri          #+#    #+#             */
/*   Updated: 2024/08/16 16:50:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	swap_stack(lst);
	ft_printf("sa\n");
}

void	sb(t_list **lst)
{
	swap_stack(lst);
	ft_printf("sb\n");
}

void	ss(t_list **lst1, t_list **lst2)
{
	swap_stack(lst1);
	swap_stack(lst2);
	ft_printf("ss\n");
}

void	pa(t_list **lst1, t_list **lst2)
{
	push_stack(lst2, lst1);
	ft_printf("pa\n");
}

void	pb(t_list **lst1, t_list **lst2)
{
	push_stack(lst1, lst2);
	ft_printf("pb\n");
}
