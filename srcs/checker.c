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

static int	is_valid_cmd(char *op)
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

static int	execute2(char *op, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(op, "rr") == 0)
	{
		rotate(stack_a, NULL, NULL);
		rotate(stack_b, NULL, NULL);
	}
	else if (ft_strcmp(op, "rra") == 0)
		inv_rotate(stack_a, NULL, NULL);
	else if (ft_strcmp(op, "rrb") == 0)
		inv_rotate(stack_b, NULL, NULL);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		inv_rotate(stack_a, NULL, NULL);
		inv_rotate(stack_b, NULL, NULL);
	}
	return (FALSE);
}

static int	execute(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!is_valid_cmd(op))
	{
		ft_putstr("Error\n");
		return (TRUE);
	}
	if (ft_strcmp(op, "sa") == 0)
		swap(*stack_a, NULL, NULL);
	else if (ft_strcmp(op, "sb") == 0)
		swap(*stack_b, NULL, NULL);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(*stack_a, NULL, NULL);
		swap(*stack_b, NULL, NULL);
	}
	else if (ft_strcmp(op, "pa") == 0)
		push(stack_b, stack_a, NULL, NULL);
	else if (ft_strcmp(op, "pb") == 0)
		push(stack_a, stack_b, NULL, NULL);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a, NULL, NULL);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b, NULL, NULL);
	else
		return (execute2(op, stack_a, stack_b));
	return (FALSE);
}

static int	boucle(t_list **stack_a, t_list **stack_b)
{
	int		exit;
	int		ret;
	char	*buff;

	exit = FALSE;
	ret = 1;
	buff = NULL;
	while (!exit && ret > 0 )
	{
		ret = get_next_line(0, &buff);
		if (ret > 0)
			exit = execute(buff, stack_a, stack_b);
		ft_strdel(&buff);
	}
	return (exit);
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
		if (!boucle(&stack_a, &stack_b))
		{
			if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
		}
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
