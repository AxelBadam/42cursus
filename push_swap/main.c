/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:56 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 12:20:17 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_argument(char **argv, t_stack **head_a)
{
	char	**tab;
	int		size;

	tab = ft_split(argv[1], ' ');
	size = ft_arg_count(tab);
	error_check_tab(size, tab, 1);
	while (--size >= 0)
		push_to_stack(head_a, ft_atoi(tab[size]), 'a');
	free_tab(tab);
}

int	main(int arg, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (arg == 2)
		handle_argument(argv, &head_a);
	else
	{
		error_check(arg, argv, 0);
		while (--arg > 0)
			push_to_stack(&head_a, ft_atoi(argv[arg]), 'a');
	}
	if (!head_a)
		exit(0);
	check_doubles(head_a);
	sorter(&head_a, &head_b);
	free_stack(head_b);
	free_stack(head_a);
	return (0);
}
