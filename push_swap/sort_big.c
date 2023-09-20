/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:25:07 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 14:02:17 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_way(t_stack *head, int value)
{
	int		size;
	int		moves;
	int		midpoint;
	t_stack	*tmp;

	moves = 0;
	size = stack_size(head);
	midpoint = size / 2;
	tmp = head;
	while (tmp->value != value)
	{
		tmp = tmp->next;
		moves++;
	}
	if (moves <= midpoint)
		return (moves);
	else
		return ((size - moves) * -1);
}

static void	move_b(t_stack **head_a, t_stack **head_b, int *tab, int *len)
{
	int	way;

	way = best_way(*head_b, tab[*len]);
	while ((*head_b)->value != tab[*len])
	{
		if ((*head_b)->next)
		{
			if ((*head_b)->next->value == tab[*len])
			{
				swap(head_b);
				break ;
			}
		}
		if (way < 0)
			reverse_rotate(head_b);
		else
			rotate(head_b);
	}
	*len -= 1;
	push_ba(head_b, head_a);
}

static void	move_part(t_stack **head_a, t_stack **head_b, int pushpoint)
{
	while (*head_a && get_next_min_value(head_a) <= pushpoint)
	{
		if ((*head_a)->value <= pushpoint)
			push_ab(head_a, head_b);
		else
			rotate(head_a);
	}
}

void	big_sort(t_stack **head_a, t_stack **head_b, int size, int *tab)
{
	int	pushpoint;
	int	len;
	int	round;

	len = size - 1;
	round = 1;
	if (size <= 100)
		round = 2;
	while (*head_a != NULL && round <= 10)
	{
		if (round == 10)
			pushpoint = tab[len];
		else
			pushpoint = tab[(size / 10) * round];
		move_part(head_a, head_b, pushpoint);
		round += 1;
		if (size <= 100)
			round += 1;
	}
	while (*head_b != NULL)
		move_b(head_a, head_b, tab, &len);
	free(tab);
}
