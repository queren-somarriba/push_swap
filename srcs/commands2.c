/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:08:45 by qsomarri          #+#    #+#             */
/*   Updated: 2024/08/16 16:51:17 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **lst)
{
	rotate_stack(lst);
	ft_printf("ra\n");
}

void	rb(t_list **lst)
{
	rotate_stack(lst);
	ft_printf("rb\n");
}

void	rr(t_list **lst1, t_list **lst2)
{
	rotate_stack(lst1);
	rotate_stack(lst2);
	ft_printf("rr\n");
}

void	rra(t_list **lst)
{
	reverse_rotate_stack(lst);
	ft_printf("rra\n");
}

void	rrb(t_list **lst)
{
	reverse_rotate_stack(lst);
	ft_printf("rrb\n");
}
