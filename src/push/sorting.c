/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:36 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/15 14:37:26 by sofiabueno       ###   ########.fr       */
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

t_stack_node	*find_min_node(t_stack_node **a)
{
	t_stack_node	*current_a;
	t_stack_node	*min_node;
	int				min_value;

	current_a = *a;
	min_value = INT_MAX;
	min_node = NULL;
	while(current_a)
	{
		if (current_a->nbr < min_value)
		{
			min_value = current_a->nbr;
			min_node = current_a;
		}
		current_a = current_a->next;
	}
	return (min_node);
}

void	find_target_node(t_stack_node **a, t_stack_node **b)
{
	int				target;
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	t_stack_node	*min_node;

	current_b = *b;
	min_node = find_min_node(a);
	while(current_b)
	{
		target = INT_MAX;
		current_a = *a;
		while(current_a)
		{
			if (current_b->nbr < current_a->nbr && target > current_a->nbr)
			{
				target = current_a->nbr;
				current_b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target == INT_MAX)
			current_b->target_node = min_node;
		current_b = current_b->next;
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
	//	printstack(b, 'b');
		//sort_three(a);
		//find_target_node(a, b);
	}
}