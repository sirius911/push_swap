/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:38:27 by clorin            #+#    #+#             */
/*   Updated: 2021/05/11 14:38:46 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			//print_stack(*stack_a, *stack_b);
		}
	}
}

/*
*	Algorithm for a stack of 4 elements
*/

void algo_four(t_list **stack_a, t_list **stack_b)
{
	int	max_a;
	int	min_a;
	int first_a;

	first_a = ft_atoi((char *)(*stack_a)->content);
	max_a = max(*stack_a);
	min_a = min(*stack_a);
	push(stack_a, stack_b, "pb");
	algo_three(stack_a);
	if (first_a == min_a)
		push(stack_b, stack_a, "pa");
	else if (first_a == max_a)
	{
		push(stack_b, stack_a, "pa");
		rotate(stack_a, "ra");
	}
	else
	{
		int nb_ra = 0;
		while (ft_atoi((char *)(*stack_a)->content) < ft_atoi((char *)(*stack_b)->content))
		{
			rotate(stack_a, "ra");
			nb_ra++;
		}
		//printf("Il y a eu %d rotation(s)\n", nb_ra);
		push(stack_b, stack_a, "pa");
		while (nb_ra > 0)
		{
			inv_rotate(stack_a, "rra");
			nb_ra--;
		}
	}
}

static void execute(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		swap(*stack_a, "sa");
	else if (ft_lstsize(*stack_a) == 3)
		algo_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		algo_four(stack_a, stack_b);
	else
		printf("stack > 4\n");
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		i = 1;
		stack_a = create_stack(argv);
		//print_stack(stack_a, stack_b);
		if (!stack_a)
		{
			printf("Error\n");
			return (1);
		}
		if (!is_sorted(stack_a))
			execute(&stack_a, &stack_b);
		print_stack(stack_a, stack_b);
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
