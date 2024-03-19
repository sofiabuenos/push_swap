/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:33:46 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/08 13:54:33 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief 
 * rotaciona os elementos da stack para cima. O primeiro vira o último.
 * -------------
 * Verifica se a lista está vazia ou com um único elemento, assim não há necessidade de rotação.
 * Last guarda o endereço do ultimo nó.
 * New_top guarda o endereço do novo topo, o antigo segundo nó.
 * Guarda o endereço do nó movido para que seja possível alterar seus campos posteriormente.
 * Altera o campo next do antigo primeiro nó, iniciando a alteracao da posição deste elemento.
 * Termina de mandar o nó para baixo da lista, linkando o campo prev ao antigo último.
 * Faz o campo next do antigo último apontar para o nó movido.
 * Atualiza o ponteiro do novo topo.
 * Altera o ponteiro para a stack para o novo topo 
 * @param stack É um ponteiro duplo para a stack, o que possibilita desreferenciar e assim alterar o ponteiro para a stack.
 */
static void	rotate(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return; 
	t_stack_node	*last;
	t_stack_node	*second;
	t_stack_node	*first;

	last = ft_findlast(stack);
	second = (*stack)->next;
	first = *stack;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*stack = second;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	printf("rb\n");
}

/**
 * @brief VERIFICAR SE PRECISO PROTEGER EM CASO DE NÃO TER NADA NA STACK B
 * 
 * @param a 
 * @param b 
 */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

