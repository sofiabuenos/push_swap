/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:36 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/08 15:28:06 by sofiabueno       ###   ########.fr       */
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
void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*cheapest;

	len_a = stack_len(a);
	while (len_a > 3)
	{
		pb(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b)
		{
			cheapest = init_nodes(a, b);
			mv_cheapest(a, b, cheapest);
		}
	top_min(a);
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
		while (push_left > 0  && len > 3)
		{
			if (current->nbr < median)
			{
				pb(a, b);
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
		sa(a);
	else if (stack_len(a) == 3)
		sort_three(a);
	else if (stack_len(a) == 5)
		sort_five(a, b);
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
