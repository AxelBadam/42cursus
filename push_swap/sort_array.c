/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:00:47 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 11:40:30 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j += 1;
		}
		i += 1;
	}
}

int	*sort_array(t_stack *head_a, int size)
{
	t_stack	*tmp;
	int		*tab;
	int		i;

	tmp = head_a;
	i = 0;
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort(tab, size);
	return (tab);
}
