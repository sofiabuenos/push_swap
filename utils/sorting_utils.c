/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:32 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/08 15:59:30 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int get_median(t_stack_node **a, int len)
{
	int				*arr;
	int				i;
	int				median;
	t_stack_node	*current;

	current = *a;
	arr = ft_calloc(len, sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = current->nbr;
		current = current->next;
		i++;
	}
	bubble_sort(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}

int	set_push_cost_a(t_stack_node **a, t_stack_node *node)
{
	int	len_a;
	int	node_cost;

	len_a = stack_len(a);
	node_cost = node->index;
	if (node->above_median == false)
		node_cost = len_a - node->index;
	return (node_cost);
}

void	move_a(t_stack_node **a, t_stack_node *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	cheapest_below_median(t_stack_node **a, int median)
{
	t_stack_node	*current;
	t_stack_node	*first;
	t_stack_node	*last;

	current = *a;
	first = NULL;
	last = NULL;
	set_current_position(a);
	while (current)
	{
		if (current->nbr < median && first == NULL)
			first = current;
		if (current->nbr < median)
			last = current;
		current = current->next;
	}
	if (last)
	{
		if (set_push_cost_a(a, first) < set_push_cost_a(a, last))
			move_a(a, first);
		else
			move_a(a, last);
	}
	else if (first)
		move_a(a, first);
}