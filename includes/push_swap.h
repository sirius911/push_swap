/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:28:57 by clorin            #+#    #+#             */
/*   Updated: 2021/05/17 12:30:12 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

void	print_stack(t_list *stack_a, t_list *stack_b);
void	push(t_list **source, t_list **dest);
void	rotate(t_list **stack);
void	inv_rotate(t_list **stack);
int		is_sorted(t_list *stack);
t_list	*create_stack(char **tab);
void	free_stack(void *content);
void	swap(t_list *stack);

#endif
