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

/*
*	return true if the first two elements of the stack are ordered
*	False otherwise
*/

int	sorted_top(t_list *stack)
{
	int	a;
	int	b;

	if (stack && stack->next)
	{
		a = ft_atoi((char *)stack->content);
		b = ft_atoi((char *)stack->next->content);
		return (a < b);
	}
	return (FALSE);
}

/*
*	Return the max value of stack
*/

int	max(t_list *stack)
{
	t_list 	*tmp;
	int		max_stack;

	tmp = stack;
	max_stack = ft_atoi((char *)stack->content);
	while (stack)
	{
		if (ft_atoi((char *)stack->content) > max_stack)
			max_stack = ft_atoi((char *)stack->content);
		stack = stack->next;
	}
	return (max_stack);
}

/*
*	return the min value of stack
*/

int	min(t_list *stack)
{
	t_list	*tmp;
	int		min_stack;

	tmp = stack;
	min_stack = ft_atoi((char *)stack->content);
	while (stack)
	{
		if (ft_atoi((char *)stack->content) < min_stack)
			min_stack = ft_atoi((char *)stack->content);
		stack = stack->next;
	}
	return (min_stack);
}

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
