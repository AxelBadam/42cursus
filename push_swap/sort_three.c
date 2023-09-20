/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:15 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 11:43:06 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_largest_value(t_stack *head)
{
	int		maxvalue;

	maxvalue = head->value;
	while (head)
	{
		if (head->value > maxvalue)
			maxvalue = head->value;
		head = head->next;
	}
	return (maxvalue);
}

void	sort_three(t_stack **head_a)
{
	int	largest_value;

	largest_value = find_largest_value((*head_a));
	if ((*head_a)->value == largest_value)
		rotate(head_a);
	else if ((*head_a)->next->value == largest_value)
		reverse_rotate(head_a);
	if ((*head_a)->value > (*head_a)->next->value)
		swap(head_a);
}
