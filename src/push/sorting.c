/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:36 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/05 15:51:35 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_n;

	biggest_n = return_biggest(a);
	if (*a == biggest_n)
		ra(a);
	if ((*a)->next == biggest_n)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
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
	long			len;
	t_stack_node	*current;

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
	long			len;
	int				median;
	t_stack_node	*current;

	len = stack_len(a);
	while (len > 3)
	{
		median = get_median(a, len);
		current = *a;
		while (current && len > 3)
		{
			if (current->nbr < median)
			{
				pb(a, b);
				len--;
			}
			current = current->next;
		}
		len = stack_len(a);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	if (stack_len(a) == 2)
		sa(a);
	else if (stack_len(a) == 3)
		sort_three(a);
	else
	{
		push_leave_three(a, b);
		sort_three(a);
		while (*b)
		{
			cheapest = init_nodes(a, b);
			mv_cheapest(a, b, cheapest);
		}
	}
	top_min(a);
}
