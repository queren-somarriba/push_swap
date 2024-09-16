/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:53:03 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/14 16:16:51 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_check_argv(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0' || !str[0])
		return (0);
	if (ft_strlen(str) > 63)
		return (0);
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int	ft_min_len(t_list *node, t_list **lst1, t_list **lst2)
{
	size_t	node_len;
	size_t	target_len;

	node_len = 0;
	target_len = 0;
	if (node->mediane == 0 && node->target->mediane == 0)
	{
		node_len = node->index;
		target_len = node->target->index;
	}
	else if (node->mediane == 1 && node->target->mediane == 1)
	{
		node_len = ft_lstsize(*lst1) - node->index;
		target_len = ft_lstsize(*lst2) - node->target->index;
	}
	return (ft_min(node_len, target_len));
}
