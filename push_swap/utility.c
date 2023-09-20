/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:07:17 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/31 11:30:09 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_new_node(int value, char stack)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->stack = stack;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	push_to_stack(t_stack **head, int value, char stack)
{
	t_stack	*new_node;

	new_node = create_new_node(value, stack);
	new_node->next = *head;
	*head = new_node;
}

int	ft_arg_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = NULL;
	if (head == NULL)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
