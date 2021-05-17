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

void	print_stack(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (ft_atoi((char *)tmp->content) > ft_atoi((char *)tmp->next->content))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	free_stack(void *content)
{
	char	*e;

	e = (char *)content;
	ft_strdel(&e);
}

int	has_duplicate(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[j], tmp) == 0)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_list	*create_stack(char **tab)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (tab[i])
		if (!ft_is_nbr(tab[i++]))
			return (NULL);
	i = 1;
	while (tab[i])
	{
		if (ft_atoll(tab[i]) > INT_MAX || ft_atoll(tab[i]) < INT_MIN)
			return (NULL);
		i++;
	}
	if (has_duplicate(tab))
		return (NULL);
	i = 1;
	while (tab[i])
		ft_lstadd_back(&stack, ft_lstnew(ft_strdup(tab[i++])));
	return (stack);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		i = 1;
		stack_a = create_stack(argv);
		if (!stack_a)
		{
			printf("Error\n");
			return (1);
		}
		print_stack(stack_a);
		printf("taille stack A : %d\n", ft_lstsize(stack_a));
		printf("%s\n",(is_sorted(stack_a)) ? "OK":"KO");
		ft_lstclear(&stack_a, &free_stack);
	}
	return (0);
}
