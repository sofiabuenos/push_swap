/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:36 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/12 16:34:13 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_n;

	biggest_n = find_biggest(a);
	if (*a == biggest_n)
		ra(a, 1);
	if ((*a)->next == biggest_n)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

void	medium_sort(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*cheapest;

	len_a = stack_len(a);
	while (len_a > 3)
	{
		pb(a, b, 1);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		cheapest = init_nodes(a, b);
		mv_cheapest(a, b, cheapest);
	}
}

void	push_leave_three(t_stack_node **a, t_stack_node **b)
{
	long			len;
	int				median;
	int				push_left;
	t_stack_node	*current;

	len = stack_len(a);
	while (len > 3)
	{
		push_left = len / 2;
		median = get_median(a, len);
		current = *a;
		while (push_left > 0 && len > 3)
		{
			if (current->nbr < median)
			{
				pb(a, b, 1);
				len--;
				push_left--;
			}
			else
				cheapest_below_median(a, median);
			current = *a;
		}
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	if (stack_len(a) == 2)
		sa(a, 1);
	else if (stack_len(a) == 3)
		sort_three(a);
	else if (stack_len(a) <= 100)
		medium_sort(a, b);
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
	set_current_position(a);
	top_min(a);
}
