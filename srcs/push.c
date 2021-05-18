/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:05:42 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:05:45 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*pop(t_list **stack)
{
	char	*tmp;
	t_list	*t_list_del;

	if (ft_lstsize(*stack) == 0)
		return (NULL);
	tmp = (char *)(*stack)->content;
	t_list_del = *stack;
	*stack = (*stack)->next;
	free(t_list_del);
	return (tmp);
}

void	push(t_list **source, t_list **dest)
{
	char	*tmp;

	if (ft_lstsize(*source) > 0)
	{
		tmp = pop(source);
		ft_lstadd_front(dest, ft_lstnew(ft_strdup(tmp)));
		ft_strdel(&tmp);
	}
}
