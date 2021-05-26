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
	t_list	*op;

	op = NULL;
	if (ft_lstsize(*stack_a) == 2)
		swap(*stack_a, "sa", &op);
	else if (ft_lstsize(*stack_a) == 3)
		algo_three(stack_a, &op);
	else if (ft_lstsize(*stack_a) == 4)
		algo_four_five(stack_a, stack_b, FALSE, &op);
	else if (ft_lstsize(*stack_a) == 5)
		algo_four_five(stack_a, stack_b, TRUE, &op);
	else 
		algo_hundred(stack_a, stack_b, &op);
	//opti(&op);

int opti = 0;
	while(op)
	{
		
		if (op->next)
		{
			if ((!ft_strcmp((char *)op->content, "sa") && !ft_strcmp((char *)op->next->content, "sb")) ||
				(!ft_strcmp((char *)op->content, "sb") && !ft_strcmp((char *)op->next->content, "sa")))
			{
				opti++;
				ft_strdel((char **)&op->content);
				op->content = ft_strdup("ss");
				t_list *op_del;
				op_del = op->next;
				if (op->next->next)
					op->next = op->next->next;
				ft_strdel((char **)&op_del->content);
				free(op->next);
			}
			if ((!ft_strcmp((char *)op->content, "ra") && !ft_strcmp((char *)op->next->content, "rb")) ||
				(!ft_strcmp((char *)op->content, "rb") && !ft_strcmp((char *)op->next->content, "ra")))
			{
				opti++;
				ft_strdel((char **)&op->content);
				op->content = ft_strdup("rr");
				t_list *op_del;
				op_del = op->next;
				if (op->next->next)
					op->next = op->next->next;
				ft_strdel((char **)&op_del->content);
				free(op->next);
			}
			if ((!ft_strcmp((char *)op->content, "rra") && !ft_strcmp((char *)op->next->content, "rrb")) ||
				(!ft_strcmp((char *)op->content, "rrb") && !ft_strcmp((char *)op->next->content, "rra")))
			{
				opti++;
				ft_strdel((char **)&op->content);
				op->content = ft_strdup("rrr");
				t_list *op_del;
				op_del = op->next;
				if (op->next->next)
					op->next = op->next->next;
				ft_strdel((char **)&op_del->content);
				free(op->next);
			}
		}
		ft_putstr((char *)op->content);
		ft_putstr("\n");
		op = op->next;
	}
	// printf("Opti = %d\n", opti);
	ft_lstclear(&op, &free_stack);
	//print_stack(*stack_a, *stack_b);
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
