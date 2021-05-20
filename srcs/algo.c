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
*	Algorithm for a stack of 3 elements
*/

void algo_three(t_list **stack)
{
	if (ft_lstsize(*stack) == 3)
	{
		while (!is_sorted(*stack))
		{
			if (!sorted_top(*stack))
				swap(*stack, "sa");
			else
				inv_rotate(stack, "rra");
		}
	}
}

/*
*	Algorithm for a stack of 4 elements
*/

void	algo_four(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, "pb");
	algo_three(stack_a);
	push_b_multiple(stack_a, stack_b, 1);
}

/*
*	Algorithm for a stack of 5 elements
*/

void	algo_five(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, "pb");
	push(stack_a, stack_b, "pb");
	algo_three(stack_a);
	push_b_multiple(stack_a, stack_b, 2);
}