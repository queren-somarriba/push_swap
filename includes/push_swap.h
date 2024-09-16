/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:26:21 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/08 19:01:17 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

t_list		**ft_split_stack(char *av);

t_list		**ft_pars_stack(char **av, int index);

void		swap_stack(t_list **stack);

void		rotate_stack(t_list **stack);

void		reverse_rotate_stack(t_list **stack);

void		push_stack(t_list **stack_a, t_list **stack_b);

t_list		*ft_lstlast_prev(t_list *lst);

void		ft_free_split(char **tab);

int			ft_check_argv(char *str);

size_t		ft_max(size_t a, size_t b);

int			ft_min(int a, int b);

void		sa(t_list **stack);

void		sb(t_list **stack);

void		ss(t_list **stack_a, t_list **stack_b);

void		pa(t_list **stack_a, t_list **stack_b);

void		pb(t_list **stack_a, t_list **stack_b);

void		ra(t_list **stack);

void		rb(t_list **stack);

void		rr(t_list **stack_a, t_list **stack_b);

void		rra(t_list **stack);

void		rrb(t_list **stack);

void		rrr(t_list **stack_a, t_list **stack_b);

void		lst_settarget(t_list **stack_a, t_list **stack_b, int mode);

void		lst_setcost(t_list **lst1, t_list **lst2);

void		lst_setindex(t_list **lst);

int			lst_data_max(t_list **lst);

int			lst_data_min(t_list **lst);

void		lst_setmediane(t_list **lst);

void		lst_setdata(t_list **lst1, t_list **lst2);

void		sort_three(t_list **lst);

t_list		*node_topush(t_list **lst);

void		sort_stack(t_list **stack, int mode);

t_list		*lst_node_min(t_list **stack);

t_list		*lst_node_max(t_list **stack);

void		set_node_pb(t_list *node, t_list **stack_a, t_list **stack_b);

void		set_node_pa(t_list *node, t_list **stack_a, t_list **stack_b);

void		push_swap(t_list **stack_a, t_list **stack_b);

void		ft_free_lst(t_list **lst);

int			ft_min_len(t_list *node, t_list **lst1, t_list **lst2);

int			check_sortstack(t_list **lst);

#endif
