/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:03:53 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/02/29 12:01:46 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **stack)
{
	int temp;
	
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp;
}
void	sa(t_stack_node **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	printf("sb\n");
}
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}











