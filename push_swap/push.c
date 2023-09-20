/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:54:43 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/20 19:29:47 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_push(t_stack *head)
{
	if (head->stack == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	push_ab(t_stack **source, t_stack **dest)
{
	t_stack	*tmp;

	if (*source == NULL)
		return ;
	(*source)->stack = 'b';
	print_push(*source);
	tmp = *dest;
	*dest = *source;
	*source = (*source)->next;
	(*dest)->next = tmp;
}

void	push_ba(t_stack **source, t_stack **dest)
{
	t_stack	*tmp;

	if (*source == NULL)
		return ;
	(*source)->stack = 'a';
	print_push(*source);
	tmp = *dest;
	*dest = *source;
	*source = (*source)->next;
	(*dest)->next = tmp;
}
