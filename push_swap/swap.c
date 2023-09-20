/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:11:06 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/30 11:52:41 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap(t_stack *head)
{
	if ((head)->stack == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	swap(t_stack **head)
{
	int	tmp;

	print_swap(*head);
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}
