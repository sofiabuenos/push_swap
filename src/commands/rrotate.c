/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:22:51 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/08 13:43:31 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief 
 * rotaciona os elementos da stack para baixo. O ultimo vira o primeiro.
 * ------------
 * Se a stack está vazia ou tem apenas um nó, não é preciso fazer nada.
 * top é o primeiro elemento da pilha inciaialmente.
 * new_top é inicialmente o último elemento da pilha e é obtido através da função ft_findlast, este elemento será movido para o topo.
 * new_last é o penúltimo elemento da pilha, ele é obtido a partir do ponteiro prev do new_top.
 * @param stack 
 */
void	rrotate(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return; 
	t_stack_node	*primeiro;
	t_stack_node	*ultimo;
	t_stack_node	*penultimo;
	primeiro = *stack;
	ultimo = ft_findlast(stack);
	penultimo = ultimo->prev;
	ultimo->next = primeiro;
	ultimo->prev = NULL;
	penultimo->next = NULL;
	primeiro->prev = ultimo;
	*stack = ultimo;
}

void	rra(t_stack_node **a)
{
	rrotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rrotate(b);
	printf("rrb\n");
}
void 	rrr(t_stack_node **a, t_stack_node **b)
{
	rrotate(a);
	rrotate(b);
	printf("rrr\n");
}
