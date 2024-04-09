/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:22:51 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/09 16:48:04 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief 
 * rotaciona os elementos da stack para baixo. O ultimo vira o primeiro.
 * ------------
 * Se a stack está vazia ou tem apenas um nó, não é preciso fazer nada.
 * top é o primeiro elemento da pilha inciaialmente.
 * new_top é inicialmente o último elemento da pilha e é obtido através da 
 * função ft_findlast, este elemento será movido para o topo.
 * new_last é o penúltimo elemento da pilha, ele é obtido a partir do 
 * ponteiro prev do new_top.
 * @param stack 
 */
void	rrotate(t_stack_node **stack)
{
	t_stack_node	*primeiro;
	t_stack_node	*ultimo;
	t_stack_node	*penultimo;

	if (!*stack || !(*stack)->next)
		return ;
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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b)
{
	rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
