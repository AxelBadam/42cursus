/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:24:10 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/02 14:17:46 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
	char				stack;
	int					index;
}						t_stack;

/*** checks    ***/
void	error_check_tab(int arg, char **argv, int tab);
void	check_doubles(t_stack *lst);
void	error_check(int arg, char **argv, int tab);
/*** the moves ***/
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	push_ab(t_stack **source, t_stack **dest);
void	push_ba(t_stack **source, t_stack **dest);
void	reverse_rotate(t_stack **head);
/*** utility   ***/
int		get_min_value(t_stack **head);
int		get_next_min_value(t_stack **head);
int		*sort_array(t_stack *head_a, int size);
void	push_to_stack(t_stack **head, int value, char stack);
int		ft_arg_count(char **argv);
void	free_stack(t_stack *head);
void	free_tab(char **tab);
int		stack_size(t_stack *head);
/*** sorting  ***/
void	sorter(t_stack **head_a, t_stack **head_b);
void	sort_five(t_stack **head_a, t_stack **head_b, int size);
void	sort_three(t_stack **head_a);
void	big_sort(t_stack **head_a, t_stack **head_b, int size, int *tab);

#endif
