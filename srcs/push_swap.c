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

static void execute(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		swap(*stack_a, "sa");
	else if (ft_lstsize(*stack_a) == 3)
		algo_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		algo_four_five(stack_a, stack_b, FALSE);
	else if (ft_lstsize(*stack_a) == 5)
		algo_four_five(stack_a, stack_b, TRUE);
	else 
		algo_hundred(stack_a, stack_b);
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
		//print_stack(stack_a, stack_b);
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
