/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three_four_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:17:32 by clorin            #+#    #+#             */
/*   Updated: 2021/05/28 12:17:41 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Renvoi le premier rang de la pile triée dont la valeur est supérieur à cible 
*/
static int	first_sup(t_list *stack, int cible)
{
	t_list	*tmp;
	int		row;

	tmp = stack;
	row = 0;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) > cible)
			return (row);
		row++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	push_b_multiple(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int	rang;
	int	max_s;
	int	min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	while (*stack_b)
	{
		if (ft_atoi((char *)(*stack_b)->content) == max_s
			|| ft_atoi((char *)(*stack_b)->content) == min_s)
		{
			min_on_top_a(stack_a, op);
			push(stack_b, stack_a, "pa", op);
		}
		else
		{
			rang = first_sup(*stack_a, ft_atoi((char *)(*stack_b)->content));
			row_on_top(stack_a, 'a', rang, op);
			push(stack_b, stack_a, "pa", op);
		}
	}
}

static void	abc(int *ab, int *ac, int *bc, t_list **stack)
{
	*ab = ft_atoi((char *)(*stack)->content)
		> ft_atoi((char *)(*stack)->next->content);
	*ac = ft_atoi((char *)(*stack)->content)
		> ft_atoi((char *)(*stack)->next->next->content);
	*bc = ft_atoi((char *)(*stack)->next->content)
		> ft_atoi((char *)(*stack)->next->next->content);
}

/*
*	Algorithm for a stack of 3 elements
*	ab = first > second
*	ac = first > third
*	bc = second > third
*	a>b		0	0		0		1	1		1
*	a>c		0	0		1		0	1		1
*	b>c		0	1		1		0	0		1
*	int		-	1		3		4	6		7
*	op		-  sa ra	rra		sa	ra	  sa rra
*/

void	algo_three(t_list **stack, t_list **op)
{
	int	ab;
	int	ac;
	int	bc;
	int	result;

	abc(&ab, &ac, &bc, stack);
	result = (ab << 2) + (ac << 1) + bc;
	if (result == 1)
	{
		swap(*stack, "sa", op);
		rotate(stack, "ra", op);
	}
	else if (result == 3)
		inv_rotate(stack, "rra", op);
	else if (result == 4)
		swap(*stack, "sa", op);
	else if (result == 6)
		rotate(stack, "ra", op);
	else if (result == 7)
	{
		swap(*stack, "sa", op);
		inv_rotate(stack, "rra", op);
	}
}

/*
*	Algorithm for a stack of 4 or 5 elements
*/

void	algo_four_five(t_list **stack_a, t_list **stack_b, int five,
		t_list **op)
{
	push(stack_a, stack_b, "pb", op);
	if (five)
		push(stack_a, stack_b, "pb", op);
	algo_three(stack_a, op);
	push_b_multiple(stack_a, stack_b, op);
	min_on_top_a(stack_a, op);
}
