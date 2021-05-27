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

void algo_three(t_list **stack, t_list **op)
{
	int ab;
	int	ac;
	int	bc;
	int result;

	ab = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->content);
	ac = ft_atoi((char *)(*stack)->content) > ft_atoi((char *)(*stack)->next->next->content);
	bc = ft_atoi((char *)(*stack)->next->content) > ft_atoi((char *)(*stack)->next->next->content);
	result = (ab << 2) + (ac << 1) + bc;
	if (result == 1)
	{
		swap(*stack, "sa", op);
		rotate(stack, "ra", op);
	}
	else if (result == 3)
		inv_rotate(stack, "rra", op);
	else if (result == 4)
		swap(*stack, "sa", op);
	else if (result == 6)
		rotate(stack, "ra", op);
	else if (result == 7)
	{
		swap(*stack, "sa", op);
		inv_rotate(stack, "rra", op);
	}
}

/*
*	Algorithm for a stack of 4 or 5 elements
*/

void	algo_four_five(t_list **stack_a, t_list **stack_b, int five, t_list **op)
{
	int max_s;
	int min_s;

	max_s = max(*stack_a);
	min_s = min(*stack_a);
	push(stack_a, stack_b, "pb", op);
	if (five)
		push(stack_a, stack_b, "pb", op);
	algo_three(stack_a, op);
	push_b_multiple(stack_a, stack_b, max_s, min_s, op);
	min_on_top_a(stack_a, op);
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
	while(stack[i] > cible)
	{
		i++;
		if (i == size)
			i = 0;
	}
	while (stack[i] < cible)
	{
		i--;
		if (i < 0)
			i = size - 1;
	}
	return (i + 1);
}

int	get_hold_first(int *stack, int size, int min, int max)
{
	int	i;
	int j;

	if (!stack)
		return (-1);
	j = min;
	while (j < max)
	{
		i = 0;
		while (i < size)
		{
			if (stack[i] >= j && stack[i] <= j + 20)
				return (i);
			i++;
		}
		j += 20;
	}
	return (-1);
}

int	get_hold_second(int *stack, int size, int min, int max)
{
	int	i;
	int j;

	if (!stack)
		return (-1);
	j = min;
	while (j < max)
	{
		i = size - 1;
		while (i >= 0)
		{
			if (stack[i] >= j && stack[i] <= j + 20)
				return (i);
			i--;
		}
		j += 20;
	}
	return (-1);
}

void	push_b_value(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int value_to_push;
	int rang;
	int size;
	int	*tab;

	value_to_push = ft_atoi((char *)(*stack_a)->content);
	if (ft_lstsize(*stack_b) == 0)
	{
		//printf("B vide\n");
		push(stack_a, stack_b, "pb", op);
	}
	else if (value_to_push > max(*stack_b)
			|| value_to_push < min(*stack_b))
	{
		//printf("%d value min or max de B\n", value_to_push);
		max_on_top_b(stack_b, op);
		push(stack_a, stack_b, "pb", op);
	}
	else
	{
		size = ft_lstsize(*stack_b);
		tab = lst_to_tab(*stack_b);
		rang = first_inf(tab, value_to_push, size);
		//printf("value = %d est a mettre au dessus de %d dans B\n", value_to_push, rang);
		row_on_top(stack_b, 'b', rang, op);
		push(stack_a, stack_b, "pb", op);
		free(tab);
	}	
}

/*
*	trie par 4 blocs 0-19 20-39 40-59 60-79 80-99
*/

void	algo_hundred(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int	size;
	int	*tab;
	int hold_first_row;
	int hold_second_row;
	int row_to_top;
	int	value_to_push;
	int	max_value;
	int min_value;

	max_value = max(*stack_a);
	min_value = min(*stack_a);

	while (*stack_a)
	{
		size = ft_lstsize(*stack_a);
		tab = lst_to_tab(*stack_a);
		//printf("size = %d\n", size);
		hold_first_row = get_hold_first(tab, size, min_value, max_value);
		hold_second_row = get_hold_second(tab, size, min_value, max_value);
		if (hold_first_row == -1 || hold_second_row == -1)
		{
			// print_stack(*stack_a, *stack_b);
			return ;
		}
		//printf("hold_first_row = %d =>value = %d\n", hold_first_row, tab[hold_first_row]);
		//printf("hold_second_row = %d =>value = %d\n", hold_second_row, tab[hold_second_row]);
		if (hold_first_row < (size - hold_second_row))
		{
			value_to_push = tab[hold_first_row];
			row_to_top = hold_first_row;
		}
		else
		{
			value_to_push = tab[hold_second_row];
			row_to_top = hold_second_row;
		}
		//printf("On met au top A le rang %d\n", row_to_top);
		row_on_top(stack_a, 'a', row_to_top, op);
		//printf("on push %d dans B\n", value_to_push);
		free(tab);
		push_b_value(stack_a, stack_b, op);
		//print_stack(*stack_a, *stack_b);
	}
	max_on_top_b(stack_b, op);
	while (*stack_b)
	{
		push(stack_b, stack_a, "pa", op);
	}
	//print_stack(*stack_a, *stack_b);
}

void	algo_hundred_pivo(t_list **stack_a, t_list **stack_b, t_list **op)
{
	int	size;
	int	*tab;
	int hold_first_row;
	int hold_second_row;
	int row_to_top;
	int	value_to_push;

	int	max_value;
	int min_value;

	max_value = max(*stack_a);
	min_value = min(*stack_a);
	int sum = 0;
	size = ft_lstsize(*stack_a);
	tab = lst_to_tab(*stack_a);

	// trie a bulle
	int tmp;
	for (int i=0 ; i < size - 1; i++)
  	{
    	for (int j=0 ; j < size - i - 1; j++)
    	{
    		if (tab[j] > tab[j+1]) 
			{
				tmp = tab[j];
        		tab[j] = tab[j+1];
        		tab[j+1] = tmp;
      		}
    	}
  	}
	for (int i=0; i < size; i++)
	{
		printf("%d\n", tab[i]);
		sum += tab[i];
	}
	if (size % 2 == 0)
	{
		// paire
	}
	else
	{
		//impaire
	}
	int moyenne = sum / size;
	printf("moyenne = %d\n", moyenne);
	while (*stack_a)
	{
		size = ft_lstsize(*stack_a);
		tab = lst_to_tab(*stack_a);
		//printf("size = %d\n", size);
		hold_first_row = get_hold_first(tab, size, min_value, max_value);
		hold_second_row = get_hold_second(tab, size, min_value, max_value);
		if (hold_first_row == -1 || hold_second_row == -1)
		{
			// print_stack(*stack_a, *stack_b);
			return ;
		}
		//printf("hold_first_row = %d =>value = %d\n", hold_first_row, tab[hold_first_row]);
		//printf("hold_second_row = %d =>value = %d\n", hold_second_row, tab[hold_second_row]);
		if (hold_first_row < (size - hold_second_row))
		{
			value_to_push = tab[hold_first_row];
			row_to_top = hold_first_row;
		}
		else
		{
			value_to_push = tab[hold_second_row];
			row_to_top = hold_second_row;
		}
		//printf("On met au top A le rang %d\n", row_to_top);
		row_on_top(stack_a, 'a', row_to_top, op);
		//printf("on push %d dans B\n", value_to_push);
		free(tab);
		push_b_value(stack_a, stack_b, op);
		//print_stack(*stack_a, *stack_b);
	}
	max_on_top_b(stack_b, op);
	while (*stack_b)
	{
		push(stack_b, stack_a, "pa", op);
	}
	//print_stack(*stack_a, *stack_b);
}

void algo_hundred3(t_list **stack_a, t_list **stack_b, t_list **op)
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
	int		max_value;
	int 	min_value;

	max_value = max(*stack_a);
	min_value = min(*stack_a);
	int sum = 0;
	size = ft_lstsize(*stack_a);
	tab = lst_to_tab(*stack_a);

	// trie a bulle
	int tmp;
	for (int i=0 ; i < size - 1; i++)
  	{
    	for (int j=0 ; j < size - i - 1; j++)
    	{
    		if (tab[j] > tab[j+1]) 
			{
				tmp = tab[j];
        		tab[j] = tab[j+1];
        		tab[j+1] = tmp;
      		}
    	}
  	}
	for (int i=0; i < size; i++)
	{
		//printf("%d\n", tab[i]);
		sum += tab[i];
	}
	//
	//calcul quartille

	int q1 = 0.25 * size;
	//printf("q1 = 0.25 * %d = %d soir value = %d\n", size, q1, tab[q1]);
	int q2 = 0.75 * size;
	//printf("q2 = 0.75 * %d = %d soit value = %d\n", size, q2, tab[q2]);
while (*stack_a)
{
	size = ft_lstsize(*stack_a);
	tab = lst_to_tab(*stack_a);
	//for(int i = 0; i < size; i++)
		//printf("tab[%d] = %d\n", i, tab[i]);
	if (size > 4)
	{
		//printf("size = %d top = [0,%d] bottom = [%d,%d]\n", size, size/4, 3*size/4,size-1);
		min_top = min_row_tab(tab, 0, q1);
		min_bottom = min_row_tab(tab, q2, size-1);
		//printf("meilleur rang au top = %d -> tab[%d] = %d\n", min_top, min_top, tab[min_top]);
		//printf("meilleur rang au bottom = %d -> tab[%d] = %d\n", min_bottom, min_bottom, tab[min_bottom]);
		if (min_top < (size - min_bottom))
		{
			//printf("TOP\n");
			row_on_top(stack_a, 'a', min_top, op);
			value_to_push = tab[min_top];
		}
		else
		{
			//printf("BOTTOM\n");
			row_on_top(stack_a, 'a', min_bottom, op);
			value_to_push = tab[min_bottom];
		}
	}
	else
	{
		min_on_top_a(stack_a, op);
		value_to_push = ft_atoi((char *)(*stack_a)->content);
	}
	free(tab);
	// on push la nouvelle valeur dans b mais ou ?
	//printf("value_to_push = %d\n", value_to_push);
	if (ft_lstsize(*stack_b) == 0)
		push(stack_a, stack_b, "pb", op);
	else if (value_to_push > max(*stack_b)
			|| value_to_push < min(*stack_b))
	{
		//printf("value min or max\n");
		max_on_top_b(stack_b, op);
		push(stack_a, stack_b, "pb", op);
	}
	else
	{
		size = ft_lstsize(*stack_b);
		tab = lst_to_tab(*stack_b);
		int rang = first_inf(tab, value_to_push, size);
		//printf("value = %d est a mettre au dessus de %d dans B\n", value_to_push, rang);
		row_on_top(stack_b, 'b', rang, op);
		push(stack_a, stack_b, "pb", op);
		free(tab);
	}
	//print_stack(*stack_a, *stack_b);
}
max_on_top_b(stack_b, op);
while (*stack_b)
	{
		push(stack_b, stack_a, "pa", op);
	}
//print_stack(*stack_a, *stack_b);
}

// void	algo_hundred2(t_list **stack_a, t_list **stack_b)
// {
// 	/*
// 	Je prend le plus petit de a et le push sur b
// 	Ensuite je poush tout B dans A
// 	middle 1460
// 	Max > 1665
// 	Min > 1250
// 	*/
// 	int max_s;
// 	int min_s;

// 	max_s = max(*stack_a);
// 	min_s = min(*stack_a);
// 	while (*stack_a)
// 	{
// 		min_on_top_a(stack_a);
// 		//print_stack(*stack_a, *stack_b);
// 		push(stack_a, stack_b, "pb");
// 		//print_stack(*stack_a, *stack_b);
// 	}
// 	//ft_putstr("ici\n");
// 	while (*stack_b)
// 	{
// 		push(stack_b, stack_a, "pa");
// 	}
// 	//print_stack(*stack_a, *stack_b);
// }