/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:17:21 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 13:58:41 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_order(t_stack *head_a)
{
	t_stack	*future;

	while (head_a)
	{
		future = head_a->next;
		while (future)
		{
			if (head_a->value > future->value)
				return (0);
			future = future->next;
		}
		head_a = head_a->next;
	}
	return (1);
}

void	sorter(t_stack **head_a, t_stack **head_b)
{
	int	size;
	int	*tab;

	size = stack_size(*head_a);
	if (check_order(*head_a))
	{
		free_stack(*head_a);
		exit(0);
	}
	if (size == 2)
		rotate(head_a);
	else if (size == 3)
		sort_three(head_a);
	else if (size == 4 || size == 5)
		sort_five(head_a, head_b, size);
	else if (size > 5)
	{
		tab = sort_array(*head_a, size);
		big_sort(head_a, head_b, size, tab);
	}
}
