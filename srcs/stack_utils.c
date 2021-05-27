/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:09:59 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:10:02 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	return true if the first two elements of the stack are ordered
*	False otherwise
*/

int	sorted_top(t_list *stack)
{
	int	a;
	int	b;

	if (stack && stack->next)
	{
		a = ft_atoi((char *)stack->content);
		b = ft_atoi((char *)stack->next->content);
		return (a < b);
	}
	return (FALSE);
}

/*
*	Return the max value of stack
*/

int	max(t_list *stack)
{
	t_list 	*tmp;
	int		max_stack;

	tmp = stack;
	max_stack = ft_atoi((char *)stack->content);
	while (stack)
	{
		if (ft_atoi((char *)stack->content) > max_stack)
			max_stack = ft_atoi((char *)stack->content);
		stack = stack->next;
	}
	return (max_stack);
}

/*
*	return the min value of stack
*/

int	min(t_list *stack)
{
	t_list	*tmp;
	int		min_stack;

	tmp = stack;
	min_stack = ft_atoi((char *)stack->content);
	while (stack)
	{
		if (ft_atoi((char *)stack->content) < min_stack)
			min_stack = ft_atoi((char *)stack->content);
		stack = stack->next;
	}
	return (min_stack);
}

/*
*	return the row of min value of tab
*/

int	min_tab(int *stack, const int size)
{
	int		min_stack;
	int		i;
	int		row;

	i = 0;
	min_stack = stack[0];
	row = i;
	while (i < size)
	{
		if (stack[i] < min_stack)
		{
			min_stack = stack[i];
			row = i;
		}
		i++;
	}
	return (row);
}

t_list	*has_duplicate(t_list *stack)
{
	t_list	*stack_tmp;
	t_list	*head_stack;
	char	*tmp;
	
	stack_tmp = stack;
	head_stack = stack;
	while(stack)
	{
		tmp = (char *)stack->content;
		//printf("tmp = %s\n", tmp);
		stack_tmp = stack->next;
		while (stack_tmp)
		{
			if (ft_strcmp(tmp, (char *)stack_tmp->content) == 0)
			{
				ft_lstclear(&head_stack, &free_stack);
				return (NULL);
			}
			stack_tmp = stack_tmp->next;
		}
		stack = stack->next;
	}
	return (head_stack);
}

// static int	has_duplicate(char **tab)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 1;
// 	while (tab[i])
// 	{
// 		tmp = tab[i];
// 		j = i + 1;
// 		while (tab[j])
// 		{
// 			if (ft_strcmp(tab[j], tmp) == 0)
// 				return (TRUE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (FALSE);
// }

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		ft_strdel(&split[i++]);
	free(split);
	split = NULL;
}

t_list	*bad_stack(t_list **stack, char **split)
{
	free_split(split);
	ft_lstclear(stack, &free_stack);
	return (NULL);
}

t_list	*create_stack(char **tab)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	char **split;

	split = NULL;
	while (tab[i])
	{
		split = ft_split(tab[i], ' ');
		int j = 0;
		while (split[j])
		{
			if (!ft_is_nbr(split[j]) || ft_atoll(split[j]) > INT_MAX
				|| ft_atoll(split[j]) < INT_MIN)
				return (bad_stack(&stack, split));
			else
				ft_lstadd_back(&stack, ft_lstnew(ft_strdup(split[j])));
			j++;
		}
		free_split(split);
		i++;
	}

	// while (tab[i])
	// 	if (!ft_is_nbr(tab[i++]))
	// 		return (NULL);
	// i = 1;
	// while (tab[i])
	// {
	// 	if (ft_atoll(tab[i]) > INT_MAX || ft_atoll(tab[i]) < INT_MIN)
	// 		return (NULL);
	// 	i++;
	// }
	// if (has_duplicate(tab))
	// 	return (NULL);
	// i = 1;
	// while (tab[i])
	// 	ft_lstadd_back(&stack, ft_lstnew(ft_strdup(tab[i++])));
	return (has_duplicate(stack));
}
