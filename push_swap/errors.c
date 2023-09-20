/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:45:02 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/25 13:49:02 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(int arg, char **argv, int tab)
{
	while (--arg > 0)
	{
		if (ft_atoi_error(argv[arg]) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			if (tab)
				free_tab(argv);
			exit(0);
		}
	}
}

void	error_check_tab(int arg, char **argv, int tab)
{
	while (arg-- > 0)
	{
		if (ft_atoi_error(argv[arg]) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			if (tab)
				free_tab(argv);
			exit(0);
		}
	}
}

static int	value_cmp(int value1, int value2)
{
	if (value1 == value2)
		return (0);
	else
		return (1);
}

void	check_doubles(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (!value_cmp(head->value, tmp->value))
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(head);
				exit(0);
			}
		tmp = tmp->next;
		}
	head = head->next;
	}	
}
