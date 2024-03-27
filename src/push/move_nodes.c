/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:24 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/03/27 14:08:34 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	if (*a != cheapest->target_node)
		while (*a != cheapest->target_node)
			ra(a);
	else
		while (*b != cheapest)
			rb(b);
}
void	rrotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	if (*a != cheapest->target_node)
		while (*a != cheapest->target_node)
			rra(a);
	else
		while (*b != cheapest)
			rrb(b);
}
void	opposite_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b);
		else
			rrb(b);
	}
}
void	move_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	// printf("\n-------------------\n");
	// printstack(a, 'A');
	// printstack(b, 'B');
	// printf("CHEAPEST: %ld\n", cheapest->nbr);
	// printf("TARGET NODE: %ld\n", cheapest->target_node->nbr);
	// printf("\n-------------------\n");

	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target_node->above_median == 0)
		rrotate_both(a, b, cheapest);
	else
		opposite_rotate(a, b, cheapest);
	pa(a, b);
}

void	top_min(t_stack_node **a)
{
	t_stack_node *min;

	min = find_min(a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}