/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:33:46 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/10 17:18:09 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief 
 * rotaciona os elementos da stack para cima. O primeiro vira o último.
 * -------------
 * Verifica se a lista está vazia ou com um único elemento, assim não há 
 * necessidade de rotação.
 * Last guarda o endereço do ultimo nó.
 * New_top guarda o endereço do novo topo, o antigo segundo nó.
 * Guarda o endereço do nó movido para que seja possível alterar seus campos
 *  posteriormente.
 * Altera o campo next do antigo primeiro nó, iniciando a alteracao da posição
 * deste elemento.
 * Termina de mandar o nó para baixo da lista, linkando o campo prev ao antigo 
 * último.
 * Faz o campo next do antigo último apontar para o nó movido.
 * Atualiza o ponteiro do novo topo.
 * Altera o ponteiro para a stack para o novo topo 
 * @param stack É um ponteiro duplo para a stack, o q possibilita desreferenciar
 * e assim alterar o ponteiro para a stack.
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second;
	t_stack_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_findlast(stack);
	second = (*stack)->next;
	first = *stack;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*stack = second;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
