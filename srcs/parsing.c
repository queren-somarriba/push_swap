/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:30:23 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/14 16:15:07 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sortstack(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst)
		return (0);
	if (!*lst)
		return (0);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_check_doubles(char **tab, size_t index)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(tab[index]);
	while (++i < index)
	{
		if (!ft_strncmp(tab[i], tab[index], ft_max(ft_strlen(tab[i]), len)))
			return (0);
	}
	return (1);
}

static int	ft_check_stack(char **tab, int mode)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (mode == 1)
		i++;
	if (!tab[0])
		return (ft_putstr_fd("Error\n", 1), 0);
	while (tab[++i])
	{
		if (!ft_check_argv(tab[i]) || !ft_check_doubles(tab, i))
			return (ft_putstr_fd("Error\n", 2), 0);
		if (ft_atol(tab[i]) < INT_MIN || ft_atol(tab[i]) > INT_MAX)
			return (ft_putstr_fd("Error\n", 2), 0);
		j = -1;
		if (mode == 1)
			j++;
		ft_printf("%ld\n", ft_atol(tab[i]));
		while (++j < i)
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (ft_putstr_fd("Error\n", 2), 0);
		}
	}
	return (1);
}

t_list	**ft_split_stack(char *av)
{
	char	**tab;
	t_list	**lst;
	size_t	i;
	t_list	*tmp;

	i = -1;
	lst = (t_list **)malloc(sizeof(t_list *));
	if (!lst)
		return (NULL);
	*lst = NULL;
	tab = ft_split(av, ' ');
	if (!tab)
		return (NULL);
	if (!ft_check_stack(tab, 0))
		return (ft_free_split(tab), ft_free_lst(lst), NULL);
	while (tab[++i])
	{
		tmp = ft_lstnew((int)ft_atol(tab[i]));
		ft_lstadd_back(lst, tmp);
	}
	ft_free_split(tab);
	return (lst);
}

t_list	**ft_pars_stack(char **av, int index)
{
	size_t	i;
	t_list	**lst;
	t_list	*tmp;

	i = index - 1;
	tmp = NULL;
	lst = (t_list **)malloc(sizeof(t_list *));
	if (!lst)
		return (NULL);
	*lst = NULL;
	if (!ft_check_stack(av, 1))
		return (ft_free_lst(lst), NULL);
	while (av[++i])
	{
		tmp = ft_lstnew((int)ft_atol(av[i]));
		ft_lstadd_back(lst, tmp);
	}
	return (lst);
}
