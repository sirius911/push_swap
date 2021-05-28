/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:13:29 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:13:30 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (ft_atoi((char *)tmp->content) > ft_atoi((char *)tmp->next->content))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

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
	t_list	*tmp;
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
