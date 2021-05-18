/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:07:41 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:07:43 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		last = ft_lstlast(*stack);
		*stack = (*stack)->next;
		last->next = tmp;
		last->next->next = NULL;
	}
}

void	inv_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		while ((*tmp).next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
