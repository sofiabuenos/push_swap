/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:54:28 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/08 14:29:12 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief A função ft_findlast caminha até ao final da lista e devolve um ponteiro para o último elemento.
 * 
 * @param stack Ponteiro duplo para a stack
 * @return t_stack_node* 
 */
t_stack_node	*ft_findlast(t_stack_node **stack)
{
	t_stack_node *last;
	if (!*stack)
		return (NULL);
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}