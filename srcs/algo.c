/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:23:40 by clorin            #+#    #+#             */
/*   Updated: 2021/05/20 16:23:44 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Return the first row of the sorted stack whose value is less than target 
*/
int	first_inf(int *stack, int target, int size)
{
	int		min_value;
	int		min_row;
	int		i;
	int		exit;

	min_row = min_tab(stack, size);
	min_value = stack[min_row];
	i = min_row;
	exit = FALSE;
	while (stack[i] > target)
	{
		i++;
		if (i == size)
			i = 0;
	}
	while (stack[i] < target)
	{
		i--;
		if (i < 0)
			i = size - 1;
	}
	return (i + 1);
}

static int	get_hold_first(int *stack, int size, int min, int max)
{
	int	i;
	int	j;
	int	coef;

	if (!stack)
		return (-1);
	j = min;
	if (size > 100)
		coef = 40;
	else
		coef = 15;
	while (j <= max)
	{
		i = 0;
		while (i < size)
		{
			if (stack[i] >= j && stack[i] <= j + coef)
				return (i);
			i++;
		}
		j += coef;
	}
	return (-1);
}

static int	get_hold_second(int *stack, int size, int min, int max)
{
	int	i;
	int	j;
	int	coef;

	if (!stack)
		return (-1);
	j = min;
	if (size > 100)
		coef = 40;
	else
		coef = 15;
	while (j <= max)
	{
		i = size - 1;
		while (i >= 0)
		{
			if (stack[i] >= j && stack[i] <= j + coef)
				return (i);
			i--;
		}
		j += coef;
	}
	return (-1);
}

static void	push_b_value(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int	value_to_push;
	int	rang;
	int	size;
	int	*tab;

	value_to_push = ft_atoi((char *)(*stack_a)->content);
	if (ft_lstsize(*stack_b) == 0)
		push(stack_a, stack_b, "pb", op);
	else if (value_to_push > max(*stack_b) || value_to_push < min(*stack_b))
	{
		max_on_top_b(stack_b, op);
		push(stack_a, stack_b, "pb", op);
	}
	else
	{
		size = ft_lstsize(*stack_b);
		tab = lst_to_tab(*stack_b);
		rang = first_inf(tab, value_to_push, size);
		row_on_top(stack_b, 'b', rang, op);
		push(stack_a, stack_b, "pb", op);
		free(tab);
	}	
}

/*
*	trie par blocs 0-19 20-39 40-59 60-79 80-99
*/

void	algo_hundred(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int	*tab;
	int	hold_first_row;
	int	hold_second_row;
	int	row_to_top;

	while (*stack_a)
	{
		tab = lst_to_tab(*stack_a);
		hold_first_row = get_hold_first(tab, ft_lstsize(*stack_a),
				min(*stack_a), max(*stack_a));
		hold_second_row = get_hold_second(tab, ft_lstsize(*stack_a),
				min(*stack_a), max(*stack_a));
		if (hold_first_row == -1 || hold_second_row == -1)
			return ;
		if (hold_first_row < (ft_lstsize(*stack_a) - hold_second_row))
			row_to_top = hold_first_row;
		else
			row_to_top = hold_second_row;
		row_on_top(stack_a, 'a', row_to_top, op);
		free(tab);
		push_b_value(stack_a, stack_b, op);
	}
	max_on_top_b(stack_b, op);
	while (*stack_b)
		push(stack_b, stack_a, "pa", op);
}
