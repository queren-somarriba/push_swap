/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:26:21 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/14 15:43:59 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

void		ft_free_lst(t_list **lst);

int			check_sortstack(t_list **lst);

void		execute_commands(char *str, t_list **stack_a, t_list **stack_b);

int			checker(t_list **stack_a, t_list **stack_b);

#endif
