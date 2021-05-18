/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:09:59 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:10:02 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	has_duplicate(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[j], tmp) == 0)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_list	*create_stack(char **tab)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (tab[i])
		if (!ft_is_nbr(tab[i++]))
			return (NULL);
	i = 1;
	while (tab[i])
	{
		if (ft_atoll(tab[i]) > INT_MAX || ft_atoll(tab[i]) < INT_MIN)
			return (NULL);
		i++;
	}
	if (has_duplicate(tab))
		return (NULL);
	i = 1;
	while (tab[i])
		ft_lstadd_back(&stack, ft_lstnew(ft_strdup(tab[i++])));
	return (stack);
}
