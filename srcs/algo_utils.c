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
*	counts the number of rotations necessary to insert nb in stack A
*/

static int	nb_ra(t_list *stack, int nb)
{
	int 	dest;
	t_list	*tmp;
// 	printf("ici nb_ra to %d\n", nb);
// printf("nb rotation = ");
	dest = 0;
	tmp = stack;
	// print_stack(stack, NULL);
	while (ft_atoi((char *)tmp->content) < nb)
	{
		// printf("content = %s\n", (char *)tmp->content);
			dest++;
			tmp = tmp->next;
	}
// printf("%d\n", dest);
	return (dest);
}

/*
*	push B after nb rotation then reverse the rotation of nb rotation
*/

static void	push_a_rotation(t_list **stack_a, t_list **stack_b, int nb_rotation)
{
	int	nb;

	nb = 0;
	while (nb < nb_rotation)
	{
		rotate(stack_a, "ra");
		nb++;
	}
	push(stack_b, stack_a, "pa");
	nb = 0;
	while (nb < nb_rotation)
	{
		inv_rotate(stack_a, "rra");
		nb++;
	}
}

void push_b_multiple(t_list **stack_a, t_list **stack_b, int len_b)
{
	int top_stack_b;
	int	i;
	int	nb_rotation;

	i = 1;
	while (i <= len_b)
	{
		top_stack_b = ft_atoi((char *)(*stack_b)->content);
		if (top_stack_b < min(*stack_a))
			push(stack_b, stack_a, "pa");
		else if (top_stack_b > max(*stack_a))
		{
			push(stack_b, stack_a, "pa");
			rotate(stack_a, "ra");
		}
		else
		{
			nb_rotation = nb_ra(*stack_a, top_stack_b);
			push_a_rotation(stack_a, stack_b, nb_rotation);
		}
		i++;
	}
}
