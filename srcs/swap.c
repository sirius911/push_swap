/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:13:11 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:13:15 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *stack)
{
	char	*tmp_a;
	char	*tmp_b;

	if (stack && stack->next)
	{
		tmp_a = (char *)stack->content;
		tmp_b = (char *)stack->next->content;
		stack->next->content = tmp_a;
		stack->content = tmp_b;
	}
}
