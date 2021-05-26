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
*	Renvoi le premier rang de la pile triée dont la valeur est supérieur à cible 
*/
int	first_sup(t_list *stack, int cible)
{
	t_list	*tmp;
	int		row;

	tmp = stack;
	row = 0;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) > cible)
			return (row);
		row++;
		tmp = tmp->next;
	}
	return (-1);
}

/*
*	Put the min value on top of the stack
*/

void	min_on_top_a(t_list **stack, t_list **op)
{
	int	row;
	int size;
	int	i;

	size = ft_lstsize(*stack);
	row = min_row(*stack);
	//printf("Min du stack = %d au rang %d\n", min(*stack), row);
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
	int size;
	int	i;

	size = ft_lstsize(*stack);
	if (size == 0)
		return ;
	row = max_row(*stack);
	//printf("Max du stack = %d au rang %d\n", max(*stack), row);
	if (row > size / 2)
	{
		i = size - row;
		while (i > 0)
		{
			inv_rotate(stack, "rrb", op);
			i--;
		}
	}
	else
	{
		i = row;
		while (i > 0)
		{
			rotate(stack, "rb", op);
			i--;
		}
	}
}

/*
*	Mets le rang donné en haut de la pile
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
		while (i > 0)
		{
			inv_rotate(stack, str, op);
			i--;
		}
	}
	else
	{
		str = ft_strdup("rx");
		str[1] = s;
		while (row > 0)
		{
			rotate(stack, str, op);
			row--;
		}
	}
	ft_strdel(&str);
}

void push_b_multiple(t_list **stack_a, t_list **stack_b, int max_s, int min_s, t_list **op)
{
	int	rang;

	while (*stack_b)
	{
		if (ft_atoi((char *)(*stack_b)->content) == max_s
			|| ft_atoi((char *)(*stack_b)->content) == min_s)
		{
			min_on_top_a(stack_a, op);
			push(stack_b, stack_a, "pa", op);
		}
		else
		{
			rang = first_sup(*stack_a, ft_atoi((char *)(*stack_b)->content));
			row_on_top(stack_a, 'a', rang, op);
			push(stack_b, stack_a, "pa", op);
		}
	}
}
