/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:14:50 by clorin            #+#    #+#             */
/*   Updated: 2021/05/28 11:14:55 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sa_sb(t_list *op_a, t_list *op_b, t_list **new_op)
{
	if (!op_b)
		return (FALSE);
	if ((!ft_strcmp((char *)op_a->content, "sa")
		&& !ft_strcmp((char *)op_b->content, "sb"))
		|| (!ft_strcmp((char *)op_a->content, "sb")
		&& !ft_strcmp((char *)op_b->content, "sa")))
	{
		ft_lstadd_back(new_op, ft_lstnew(ft_strdup("ss")));
		return (TRUE);
	}
	else
		return (FALSE);
}

static int ra_rb(t_list *op_a, t_list *op_b, t_list **new_op)
{
	if (!op_b)
		return (FALSE);
	if ((!ft_strcmp((char *)op_a->content, "ra")
		&& !ft_strcmp((char *)op_b->content, "rb"))
		|| (!ft_strcmp((char *)op_a->content, "rb")
		&& !ft_strcmp((char *)op_b->content, "ra")))
	{
		ft_lstadd_back(new_op, ft_lstnew(ft_strdup("rr")));
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	rra_rrb(t_list *op_a, t_list *op_b, t_list **new_op)
{
	if (!op_b)
		return (FALSE);
	if ((!ft_strcmp((char *)op_a->content, "rra")
		&& !ft_strcmp((char *)op_b->content, "rrb"))
		|| (!ft_strcmp((char *)op_a->content, "rrb")
		&& !ft_strcmp((char *)op_b->content, "rra")))
	{
		ft_lstadd_back(new_op, ft_lstnew(ft_strdup("rrr")));
		return (TRUE);
	}
	else
		return (FALSE);
}

t_list	*optimize(t_list *op)
{
	t_list	*new_op;
	t_list	*head_op;

	new_op = NULL;
	head_op = op;
	while (op)
	{
			if (sa_sb(op, op->next, &new_op))
				op = op->next;
			else if (ra_rb(op, op->next, &new_op))
				op = op->next;
			else if (rra_rrb(op, op->next, &new_op))
				op = op->next;
			else
				ft_lstadd_back(&new_op, ft_lstnew(ft_strdup((char *)op->content)));	
			op = op->next;
	}
	ft_lstclear(&head_op, &free_stack);	
	return (new_op);
}

