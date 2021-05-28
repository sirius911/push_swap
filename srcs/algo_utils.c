/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:27:38 by clorin            #+#    #+#             */
/*   Updated: 2021/05/20 16:27:41 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	return the row of the min value of the stack
*/
int	min_row(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		row;

	tmp = stack;
	i = 0;
	row = 0;
	min = ft_atoi((char *)tmp->content);
	while (tmp)
	{
		if (min > ft_atoi((char *)tmp->content))
		{
			min = ft_atoi((char *)tmp->content);
			row = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (row);
}

/*
*	return the row of the max value of the stack
*/
int	max_row(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		row;

	tmp = stack;
	i = 0;
	row = 0;
	max = ft_atoi((char *)tmp->content);
	while (tmp)
	{
		if (max < ft_atoi((char *)tmp->content))
		{
			max = ft_atoi((char *)tmp->content);
			row = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (row);
}

/*
*	Put the min value on top of the stack
*/

void	min_on_top_a(t_list **stack, t_list **op)
{
	int	row;
	int	size;
	int	i;

	size = ft_lstsize(*stack);
	row = min_row(*stack);
	if (row > size / 2)
	{
		i = size - row;
		while (i > 0)
		{
			inv_rotate(stack, "rra", op);
			i--;
		}
	}
	else
	{
		i = row;
		while (i > 0)
		{
			rotate(stack, "ra", op);
			i--;
		}
	}
}

/*
*	Put the max value on top of the stack
*/

void	max_on_top_b(t_list **stack, t_list **op)
{
	int	row;
	int	size;
	int	i;

	size = ft_lstsize(*stack);
	if (size == 0)
		return ;
	row = max_row(*stack);
	if (row > size / 2)
	{
		i = size - row;
		while (i-- > 0)
			inv_rotate(stack, "rrb", op);
	}
	else
	{
		i = row;
		while (i-- > 0)
			rotate(stack, "rb", op);
	}
}

/*
*	put the row on top of the stack
*/

void	row_on_top(t_list **stack, char s, int row, t_list **op)
{
	int		size;
	char	*str;
	int		i;

	size = ft_lstsize(*stack);
	if (row > size / 2)
	{
		str = ft_strdup("rrx");
		str[2] = s;
		i = size - row;
		while (i-- > 0)
			inv_rotate(stack, str, op);
	}
	else
	{
		str = ft_strdup("rx");
		str[1] = s;
		while (row-- > 0)
			rotate(stack, str, op);
	}
	ft_strdel(&str);
}
