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
		if (!stack_a)
		{
			printf("Error\n");
			return (1);
		}
		printf("sa\n");
		printf("pb\n");
		printf("pb\n");
		printf("pb\n");
		printf("sa\n");
		printf("pa\n");
		printf("pa\n");
		printf("pa\n");
		printf("pa\n");
		ft_lstclear(&stack_a, &free_stack);
		ft_lstclear(&stack_b, &free_stack);
	}
	return (0);
}
