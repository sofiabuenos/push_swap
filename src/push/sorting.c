/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:36 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/20 15:58:34 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_n;

	biggest_n = return_biggest(a);
	if (*a == biggest_n)
		ra(a);
	if ((*a)->next == biggest_n)
		rra(a);
	if((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
/**
 * @brief conta quantos elementos tem a stack
 * PODE IR PARA UTILS
 * @param stack 
 * @return long 
 */
long	stack_len(t_stack_node **stack)
{
	long	len;
	t_stack_node *current;

	len = 0;
	current = *stack;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	push_leave_three(t_stack_node **a, t_stack_node **b)
{
	long	len;

	len = stack_len(a);
	printf("len: %ld\n", len);
	while (len > 3)
	{
		pb(a, b);
		len --;
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if(stack_len(a) == 2)
		sa(a);
	else if (stack_len(a) == 3)
		sort_three(a);
	else
	{
		push_leave_three(a, b);
		sort_three(a);
		init_nodes(a, b);
	}
}