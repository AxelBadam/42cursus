/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:58:40 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 14:13:41 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_last(t_stack **head_a, int size)
{
	if (size == 5)
	{
		if ((*head_a)->next->next->next->next->value == get_min_value(head_a))
			reverse_rotate(head_a);
	}
	if ((*head_a)->next->next->next->value == get_min_value(head_a))
	{
		reverse_rotate(head_a);
		if (size == 5)
			reverse_rotate(head_a);
	}
}

static void	push_smallest(t_stack **head_a, t_stack **head_b, int size)
{
	int	i;

	i = 1;
	while (i)
	{
		if ((*head_a)->value == get_min_value(head_a))
		{
			push_ab(head_a, head_b);
			if (size == 5)
				push_ab(head_a, head_b);
			i = 0;
		}
		else
			rotate(head_a);
	}
}

static void	check_worst_case(t_stack **head_a, t_stack **head_b)
{
	if ((*head_b)->value > (*head_a)->next->value && \
			(*head_b)->value < (*head_a)->next->next->value)
	{
		reverse_rotate(head_a);
		push_ba(head_b, head_a);
		rotate(head_a);
		rotate(head_a);
	}
}

void	sort_five(t_stack **head_a, t_stack **head_b, int size)
{
	check_last(head_a, size);
	push_smallest(head_a, head_b, size);
	sort_three(head_a);
	if (size == 4)
	{
		push_ba(head_b, head_a);
		return ;
	}
	check_worst_case(head_a, head_b);
	push_ba(head_b, head_a);
	if ((*head_a)->value > (*head_a)->next->value && \
			(*head_a)->value < (*head_a)->next->next->value)
		swap(head_a);
	else if ((*head_a)->value > (*head_a)->next->next->next->value)
		rotate(head_a);
	push_ba(head_b, head_a);
}
