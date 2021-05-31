/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:42:36 by clorin            #+#    #+#             */
/*   Updated: 2021/05/28 14:42:39 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	return the row of max value of tab
*/

int	max_tab(int *stack, const int size)
{
	int		max_stack;
	int		i;
	int		row;

	i = 0;
	max_stack = stack[0];
	row = i;
	while (i < size)
	{
		if (stack[i] > max_stack)
		{
			max_stack = stack[i];
			row = i;
		}
		i++;
	}
	return (row);
}

/*
*	return the row of min value of tab
*/

int	min_tab(int *stack, const int size)
{
	int		min_stack;
	int		i;
	int		row;

	i = 0;
	min_stack = stack[0];
	row = i;
	while (i < size)
	{
		if (stack[i] < min_stack)
		{
			min_stack = stack[i];
			row = i;
		}
		i++;
	}
	return (row);
}

/*
*	returns the stack as an array
*/
int	*lst_to_tab(t_list *stack)
{
	int		*tab;
	t_list	*tmp;
	int		i;

	tmp = stack;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	if (!tab)
		return (NULL);
	i = 0;
	while (tmp)
	{
		tab[i++] = ft_atoi((char *)tmp->content);
		tmp = tmp->next;
	}
	return (tab);
}

/*
*	returns the rank of the minimum value of the array
*	between the indices [min, max]
*/
int	min_row_tab(int *stack, int min, int max)
{
	int		i;
	int		min_value;
	int		row;

	i = min;
	row = i;
	min_value = stack[i++];
	while (i <= max)
	{
		if (min_value > stack[i])
		{
			min_value = stack[i];
			row = i;
		}
		i++;
	}
	return (row);
}
