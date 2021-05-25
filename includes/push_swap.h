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
void	push(t_list **source, t_list **dest, char *str);
void	rotate(t_list **stack, char *str);
void	inv_rotate(t_list **stack, char *str);
int		max(t_list *stack);
int		min(t_list *stack);
int		min_tab(int *stack, const int size);
int		is_sorted(t_list *stack);
int		sorted_top(t_list *stack);
t_list	*create_stack(char **tab);
void	free_stack(void *content);
void	swap(t_list *stack, char *str);
void 	algo_three(t_list **stack);
void	algo_four_five(t_list **stack_a, t_list **stack_b, int five);
void	algo_hundred(t_list **stack_a, t_list **stack_b);
void 	push_b_multiple(t_list **stack_a, t_list **stack_b, int max_s, int min_s);
void	row_on_top(t_list **stack, char s, int row);
void	min_on_top_a(t_list **stack);
void	max_on_top_b(t_list **stack);
int		first_sup(t_list *stack, int cible);
int		min_row(t_list *stack);
int		max_row(t_list *stack);

#endif
