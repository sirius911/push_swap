/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:37:35 by clorin            #+#    #+#             */
/*   Updated: 2021/05/10 15:37:39 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_cmd(char *op)
{
	if (!ft_strcmp(op, "sa")
		|| !ft_strcmp(op, "sb")
		|| !ft_strcmp(op, "ss")
		|| !ft_strcmp(op, "pa")
		|| !ft_strcmp(op, "pb")
		|| !ft_strcmp(op, "ra")
		|| !ft_strcmp(op, "rb")
		|| !ft_strcmp(op, "rr")
		|| !ft_strcmp(op, "rra")
		|| !ft_strcmp(op, "rrb")
		|| !ft_strcmp(op, "rrr"))
		return (TRUE);
	return (FALSE);
}

static int	execute(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!is_valid_cmd(op))
	{
		printf("Error\n");
		return (TRUE);
	}
	if (ft_strcmp(op, "sa") == 0)
		swap(*stack_a, NULL);
	else if (ft_strcmp(op, "sb") == 0)
		swap(*stack_b, NULL);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(*stack_a, NULL);
		swap(*stack_b, NULL);
	}
	else if (ft_strcmp(op, "pa") == 0)
		push(stack_b, stack_a, NULL);
	else if (ft_strcmp(op, "pb") == 0)
		push(stack_a, stack_b, NULL);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a, NULL);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b, NULL);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
	}
	else if (ft_strcmp(op, "rra") == 0)
		inv_rotate(stack_a, NULL);
	else if (ft_strcmp(op, "rrb") == 0)
		inv_rotate(stack_b, NULL);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		inv_rotate(stack_a, NULL);
		inv_rotate(stack_b, NULL);
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = create_stack(argv);
		if (!stack_a)
		{
			ft_putstr("Error\n");
			return (1);
		}
		//print_stack(stack_a, stack_b);
		int exit = FALSE;
		int ret;
		char *buff;
		while (!exit &&(ret = get_next_line(0, &buff)) > 0)
		{
			exit = execute(buff, &stack_a, &stack_b);
			free(buff);
			//print_stack(stack_a, stack_b);
		}
		//print_stack(stack_a, stack_b);
		// printf("Swap A\n");
		// swap(stack_a);
		// printf("Swap B\n");
		// swap(stack_b);
		// print_stack(stack_a, stack_b);

		// printf("push A \n");
		// push(&stack_b, &stack_a);
		// print_stack(stack_a, stack_b);

		// printf("push B \n");
		// push(&stack_a, &stack_b);
		// print_stack(stack_a, stack_b);

		// printf("rotate A \n");
		// rotate(&stack_a);
		// print_stack(stack_a, stack_b);

		// printf("inv_rotate A \n");
		// inv_rotate(&stack_a);
		// print_stack(stack_a, stack_b);

		// printf("inv_rotate B \n");
		// inv_rotate(&stack_b);
		// print_stack(stack_a, stack_b);

		// printf("taille stack A : %d\n", ft_lstsize(stack_a));
		// printf("taille stack B : %d\n", ft_lstsize(stack_b));
		if (!exit)
			ft_putstr((is_sorted(stack_a) && ft_lstsize(stack_b) == 0) ? "OK\n":"KO\n");
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
