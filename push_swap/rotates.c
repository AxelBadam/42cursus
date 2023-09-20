/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:35:33 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/27 14:55:39 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_rotate(t_stack *head)
{
	if (head->stack == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	print_rotate(*head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp = tmp->next;
	tmp->next = NULL;
}

static void	print_reverse_rotate(t_stack *head)
{
	if (head->stack == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*second_last;
	t_stack	*tmp;

	print_reverse_rotate(*head);
	tmp = *head;
	second_last = *head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	*head = second_last->next;
	(*head)->next = tmp;
	second_last->next = NULL;
}
