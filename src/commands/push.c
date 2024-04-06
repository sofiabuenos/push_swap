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

static void	push(t_stack_node **dest, t_stack_node **src ) // esta funcao recebe um ponteiro para ponteiro para o topo de cada stack. 
{
	t_stack_node	*push_node;

	if (!*src) // aqui, acesso por desreferenciação o ponteiro que aponta para um t_stack_node. caso ele esteja vazio, isso significa que nao aponta para nenhum nó, ou seja, a stack está vazia.
		return;
	push_node = *src; // aqui, desreferenciamos src (ponteiro duplo) e passamos para a var. temporária push_node o endereço de memória do nó de topo.
	*src = (*src)->next; // nesta linha, alteramos o endereço de memória do ponteiro src para o próximo elemento da stack. Ou seja, tiramos desse ponteiro a referencia para o nó que estava no topo, passando para o seguinte.
	if (*src)
		(*src)->prev = NULL;
	//push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node; // aqui acedemos ao campo next do nó armazenado em push_node, que nos dá acesso ao proximo nó e depois disso, alteramos o campo previous do nó a seguir ao topo.
		*dest = push_node;
	}
}

/**
 * @brief takes the first element of b and pushes to the top of a
 * 
 * @param a 
 * @param b 
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	printf("pa\n");
}

/**
 * @brief takes the first element on top of a and pushes to the top of b
 * 
 * @param b 
 * @param a 
 */
void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	printf("pb\n");
}