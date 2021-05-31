/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:55:20 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 12:55:51 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	first_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		diff;
	int		i;

	tmp_a = stack_a;
	tmp_b = stack_b;
	i = 0;
	diff = ft_lstsize(tmp_a) - ft_lstsize(tmp_b);
	while (tmp_a)
	{
		printf("%s", (char *)tmp_a->content);
		tmp_a = tmp_a->next;
		i++;
		if (i > diff && tmp_b)
		{
			printf("\t\t%s", (char *)tmp_b->content);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	printf("A\t\tB\n");
}

static void	first_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		diff;
	int		i;

	tmp_a = stack_a;
	tmp_b = stack_b;
	i = 0;
	diff = ft_lstsize(tmp_a) - ft_lstsize(tmp_b);
	while (tmp_b)
	{
		i++;
		if (i > diff && tmp_a)
		{
			printf("%s", (char *)tmp_a->content);
			tmp_a = tmp_a->next;
		}
		printf("\t\t%s", (char *)tmp_b->content);
		tmp_b = tmp_b->next;
		printf("\n");
	}
	printf("A\t\tB\n");
}

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	int	diff;

	diff = ft_lstsize(stack_a) - ft_lstsize(stack_b);
	if (diff >= 0)
		first_a(stack_a, stack_b);
	else
		first_b(stack_a, stack_b);
}
