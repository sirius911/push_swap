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

static void execute(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 3)
	{
		while (!is_sorted(*stack_a))
		{
			if (!sorted_top(*stack_a))
			{
				swap(*stack_a);
				printf("sa\n");
			}
			else
			{
				inv_rotate(stack_a);
				printf("rra\n");
			}
			//print_stack(*stack_a, *stack_b);
		}
	}
	else
		printf("stack != 3\n");
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
		print_stack(stack_a, stack_b);
		if (!stack_a)
		{
			printf("Error\n");
			return (1);
		}
		execute(&stack_a, &stack_b);
		print_stack(stack_a, stack_b);
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
