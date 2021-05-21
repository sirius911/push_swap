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
*	ab = first > second
*	ac = first > third
*	bc = second > third
*	a>b		0	0		0		1	1		1
*	a>c		0	0		1		0	1		1
*	b>c		0	1		1		0	0		1
*	int		-	1		3		4	6		7
*	op		-  sa ra	rra		sa	ra	  sa rra
*/

void algo_three(t_list **stack)
{
	int ab;
	int	ac;
	int	bc;
	int result;

	ab = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->content);
	ac = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->next->content);
	bc = ft_atoi((char *)(*stack)->next->content) > ft_atoi((char *)(*stack)->next->next->content);;
	result = (ab << 2) + (ac << 1) + bc;
	if (result == 1)
	{
		swap(*stack, "sa");
		rotate(stack, "ra");
	}
	else if (result == 3)
		inv_rotate(stack, "rra");
	else if (result == 4)
		swap(*stack, "sa");
	else if (result == 6)
		rotate(stack, "ra");
	else if (result == 7)
	{
		swap(*stack, "sa");
		inv_rotate(stack, "rra");
	}
}

/*
*	Algorithm for a stack of 4 or 5 elements
*/

void	algo_four_five(t_list **stack_a, t_list **stack_b, int five)
{
	int max_s;
	int min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	push(stack_a, stack_b, "pb");
	if (five)
		push(stack_a, stack_b, "pb");
	algo_three(stack_a);
	push_b_multiple(stack_a, stack_b, max_s, min_s);
	min_on_top_a(stack_a);
}

void	algo_hundred(t_list **stack_a, t_list **stack_b)
{
	/*
	je divise size par 4 (je trouve un nombre de chiffre)
	je prend le plus petit de premier quart et regarde son rang
	je regarde le rang du plus petit du 4eme quart
	je met en haut celui qui est le plus facile a mettre
	je push en b en 
	*/
	int max_s;
	int min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	while (*stack_a)
	{
		min_on_top_a(stack_a);
		//print_stack(*stack_a, *stack_b);
		push(stack_a, stack_b, "pb");
		//print_stack(*stack_a, *stack_b);
	}
	//ft_putstr("ici\n");
	while (*stack_b)
	{
		push(stack_b, stack_a, "pa");
	}
	//print_stack(*stack_a, *stack_b);
}