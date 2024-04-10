/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:03:53 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/10 17:19:43 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **stack)
{
	int	temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
