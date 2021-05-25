/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:23:40 by clorin            #+#    #+#             */
/*   Updated: 2021/05/20 16:23:44 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Algorithm for a stack of 3 elements
*	ab = first > second
*	ac = first > third
*	bc = second > third
*	a>b		0	0		0		1	1		1
*	a>c		0	0		1		0	1		1
*	b>c		0	1		1		0	0		1
*	int		-	1		3		4	6		7
*	op		-  sa ra	rra		sa	ra	  sa rra
*/

void algo_three(t_list **stack)
{
	int ab;
	int	ac;
	int	bc;
	int result;

	ab = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->content);
	ac = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->next->content);
	bc = ft_atoi((char *)(*stack)->next->content) > ft_atoi((char *)(*stack)->next->next->content);;
	result = (ab << 2) + (ac << 1) + bc;
	if (result == 1)
	{
		swap(*stack, "sa");
		rotate(stack, "ra");
	}
	else if (result == 3)
		inv_rotate(stack, "rra");
	else if (result == 4)
		swap(*stack, "sa");
	else if (result == 6)
		rotate(stack, "ra");
	else if (result == 7)
	{
		swap(*stack, "sa");
		inv_rotate(stack, "rra");
	}
}

/*
*	Algorithm for a stack of 4 or 5 elements
*/

void	algo_four_five(t_list **stack_a, t_list **stack_b, int five)
{
	int max_s;
	int min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	push(stack_a, stack_b, "pb");
	if (five)
		push(stack_a, stack_b, "pb");
	algo_three(stack_a);
	push_b_multiple(stack_a, stack_b, max_s, min_s);
	min_on_top_a(stack_a);
}

int	*lst_to_tab(t_list *stack)
{
	int		*tab;
	t_list	*tmp;
	int		i;

	tmp = stack;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	if (!tab)
		return (NULL);
	i = 0;
	while (tmp)
	{
		tab[i++] = ft_atoi((char *)tmp->content);
		tmp = tmp->next;
	}
	return (tab);
}

int	min_row_tab(int *stack, int min, int max)
{
	int		i;
	int		min_value;
	int		row;

	i = min;
	row = i;
	min_value = stack[i++];
	//printf("scan de %d a %d\n", min, max);
	while (i <= max)
	{
		if (min_value > stack[i])
		{
			min_value = stack[i];
			row = i;
		}
		i++;
	}
	return (row);
}

/*
*	Renvoi le premier rang de la pile triée dont la valeur est inferieur à cible 
*/
int	first_inf(int *stack, int cible, int size)
{
	int		min_value;
	int		min_row;
	int		i;
	int		exit;

	min_row = min_tab(stack, size);
	min_value = stack[min_row];
	i = min_row;
	exit = FALSE;
	//printf("first_inf cible = %d min row = %d\n", cible, min_row);
	while(stack[i] > cible)
	{
		i++;
		if (i == size)
			i = 0;
	}
	//printf("sortie 1 i = %d\n", i);
	while (stack[i] < cible)
	{
		i--;
		if (i < 0)
			i = size - 1;
	}
	// while(!exit)
	// {
	// 	printf("stack[%d] = %d\n", i, stack[i]);
	// 	if (cible > stack[i])
	// 		exit = TRUE;
	// 	else
	// 	{
	// 		i--;
	// 		if (i == 0)
	// 			i = size;
	// 	}
	// }
	// printf("sortie exit i = %d\n", i);
	// while (stack[i] < cible && i >= 0)
	// 	i--;
	//printf("avant return i = %d\n", i);
	return (i + 1);
}

void algo_hundred(t_list **stack_a, t_list **stack_b)
{
	/*
	je divise size par 4 (je trouve un nombre de chiffre)
	je prend le plus petit de premier quart et regarde son rang
	je regarde le rang du plus petit du 4eme quart
	je met en haut celui qui est le plus facile a mettre
	je push en b en 
	*/
	int		size;
	int		*tab;
	int 	min_top;
	int 	min_bottom;
	int		value_to_push;

while (*stack_a)
{
	size = ft_lstsize(*stack_a);
	tab = lst_to_tab(*stack_a);
	//for(int i = 0; i < size; i++)
		//printf("tab[%d] = %d\n", i, tab[i]);
	if (size > 4)
	{
		//printf("size = %d top = [0,%d] bottom = [%d,%d]\n", size, size/4, 3*size/4,size-1);
		min_top = min_row_tab(tab, 0, size / 3);
		min_bottom = min_row_tab(tab, (1 * size / 3), size-1);
		//printf("meilleur rang au top = %d -> tab[%d] = %d\n", min_top, min_top, tab[min_top]);
		//printf("meilleur rang au bottom = %d -> tab[%d] = %d\n", min_bottom, min_bottom, tab[min_bottom]);
		if (min_top < (size - min_bottom))
		{
			//printf("TOP\n");
			row_on_top(stack_a, 'a', min_top);
			value_to_push = tab[min_top];
		}
		else
		{
			//printf("BOTTOM\n");
			row_on_top(stack_a, 'a', min_bottom);
			value_to_push = tab[min_bottom];
		}
	}
	else
	{
		min_on_top_a(stack_a);
		value_to_push = ft_atoi((char *)(*stack_a)->content);
	}
	free(tab);
	// on push la nouvelle valeur dans b mais ou ?
	//printf("value_to_push = %d\n", value_to_push);
	if (ft_lstsize(*stack_b) == 0)
		push(stack_a, stack_b, "pb");
	else if (value_to_push > max(*stack_b)
			|| value_to_push < min(*stack_b))
	{
		//printf("value min or max\n");
		max_on_top_b(stack_b);
		push(stack_a, stack_b, "pb");
	}
	else
	{
		size = ft_lstsize(*stack_b);
		tab = lst_to_tab(*stack_b);
		int rang = first_inf(tab, value_to_push, size);
		//printf("value = %d est a mettre au dessus de %d dans B\n", value_to_push, rang);
		row_on_top(stack_b, 'b', rang);
		push(stack_a, stack_b, "pb");
		free(tab);
	}
	//print_stack(*stack_a, *stack_b);
}
max_on_top_b(stack_b);
while (*stack_b)
	{
		push(stack_b, stack_a, "pa");
	}
//print_stack(*stack_a, *stack_b);
}

void	algo_hundred2(t_list **stack_a, t_list **stack_b)
{
	/*
	Je prend le plus petit de a et le push sur b
	Ensuite je poush tout B dans A
	middle 1460
	Max > 1665
	Min > 1250
	*/
	int max_s;
	int min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	while (*stack_a)
	{
		min_on_top_a(stack_a);
		//print_stack(*stack_a, *stack_b);
		push(stack_a, stack_b, "pb");
		//print_stack(*stack_a, *stack_b);
	}
	//ft_putstr("ici\n");
	while (*stack_b)
	{
		push(stack_b, stack_a, "pa");
	}
	//print_stack(*stack_a, *stack_b);
}