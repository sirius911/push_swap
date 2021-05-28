/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:10:52 by clorin            #+#    #+#             */
/*   Updated: 2021/05/18 13:10:54 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(void *content)
{
	char	*e;

	e = (char *)content;
	ft_strdel(&e);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		ft_strdel(&split[i++]);
	free(split);
	split = NULL;
}
