#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:33:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/07 14:22:12 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src )
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

/**
 * @brief takes the first element of b and pushes to the top of a
 * 
 * @param a destination
 * @param b origin
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	printf("pa\n");
}

/**
 * @brief takes the first element on top of a and pushes to the top of b
 * 
 * @param a origin
 * @param b destination
 */
void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	printf("pb\n");
}
