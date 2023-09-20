/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:29:36 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 13:56:25 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *head;
	min = tmp;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->value);
}

int	get_next_min_value(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	tmp = *head;
	while (tmp)
	{
		if ((!has_min || tmp->value < min->value))
		{
			min = tmp;
			has_min = 1;
		}
		tmp = tmp->next;
	}
	return (min->value);
}

int	stack_size(t_stack *head)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
