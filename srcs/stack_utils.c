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

static t_list	*has_duplicate(t_list *stack)
{
	t_list	*stack_tmp;
	t_list	*head_stack;
	char	*tmp;

	stack_tmp = stack;
	head_stack = stack;
	while (stack)
	{
		tmp = (char *)stack->content;
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

static t_list	*bad_stack(t_list **stack, char **split)
{
	free_split(split);
	ft_lstclear(stack, &free_stack);
	return (NULL);
}

t_list	*create_stack(char **tab)
{
	t_list	*stack;
	int		i;
	char	**split;
	int		j;

	i = 1;
	stack = NULL;
	split = NULL;
	while (tab[i])
	{
		split = ft_split(tab[i], ' ');
		j = 0;
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
	return (has_duplicate(stack));
}
