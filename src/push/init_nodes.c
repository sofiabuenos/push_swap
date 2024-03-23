/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:54 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/20 16:49:37 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief POR NO UTILS
 * 
 * @param a 
 * @return t_stack_node* 
 */
t_stack_node	*find_min(t_stack_node **a)
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

void	set_target(t_stack_node **a, t_stack_node **b)
{
	int				target;
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	t_stack_node	*min_node;

	current_b = *b;
	min_node = find_min(a);
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
/**
 * @brief initiates the index and the bolean value above_median. 
 * This needs to be recalculated everytime the progam moves a node.
 * 
 * @param stack 
 */
void	set_current_position(t_stack_node **stack)
{
	int	i;
	int	median;
	t_stack_node *current;

	i = 0;
	median = stack_len(stack) / 2;
	printf("\nmedian = %d", median);
	current = *stack;
	if (! current)
		return ;
	while(current)
	{
		(current)->index = i;
		if (i <= median)
			(current)->above_median = true;
		else
			(current)->above_median = false;
		current = current->next;
		i++;
	}
}

void	set_push_cost(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	len_b;
	t_stack_node *current;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current = *b;

	while(current)
	{
		current->push_cost = current->index;
		if (current->above_median == false)
			current->push_cost = len_b - current->index;
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += len_a - (current->target_node->index);
		current = current->next;
	}
}

void	set_cheapest(t_stack_node **b)
{
	int	lower_cost;
	t_stack_node *best_node;
	t_stack_node *current;

	lower_cost = INT_MAX;
	current = *b;
	if (!*b)
		return ;
	while (current)
	{
		if (current->push_cost < lower_cost)
		{
			lower_cost = current->push_cost;
			best_node = current;
		}
		current = current->next;
	}
	best_node->cheapest = true;
}

void	init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_target(a, b);
	set_current_position(a);
	set_current_position(b);
	set_push_cost(a, b);
	set_cheapest(b);
}