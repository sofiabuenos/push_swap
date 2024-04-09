/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:16:19 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/08 16:04:49 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief A função ft_findlast caminha até ao final da lista e devolve 
 * um ponteiro para o último elemento.
 * 
 * @param stack Ponteiro duplo para a stack
 * @return t_stack_node* 
 */
t_stack_node	*ft_findlast(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack)
		return (NULL);
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

/**
 * @brief conta quantos elementos tem a stack
 * PODE IR PARA UTILS
 * @param stack 
 * @return long 
 */
long	stack_len(t_stack_node **stack)
{
	long			len;
	t_stack_node	*current;

	len = 0;
	current = *stack;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_stack_node	*find_min(t_stack_node **a)
{
	t_stack_node	*current_a;
	t_stack_node	*min_node;
	int				min_value;

	current_a = *a;
	min_value = INT_MAX;
	min_node = NULL;
	while (current_a)
	{
		if (current_a->nbr < min_value)
		{
			min_value = current_a->nbr;
			min_node = current_a;
		}
		current_a = current_a->next;
	}
	return (min_node);
}
t_stack_node	*return_biggest(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*bigger;

	if (!stack)
		return (NULL);
	current = *stack;
	bigger = current;
	while (current != NULL)
	{
		if(bigger->nbr < current->nbr)
			bigger = current;
		current = current->next;
	}
	return (bigger);
}

/**
 * @brief visualiza os numeros da stack
 * 
 * @param stack 
 * @param c 
 */
void	printstack(t_stack_node **stack, char c)
{
	t_stack_node	*temp = *stack;

	printf("\nSTACK %c\n", c);
	while(temp != NULL)
	{
		printf("%ld\n\n", temp->nbr);
		// printf("nbr: %ld\n index: %d\n push_cost: %d \n above_median: %d\n cheapest: %d\n"
		//  	"target: %p\n next: %p\n perv: %p\n\n\n", temp->nbr, temp->index, temp->push_cost,
		//  	temp->above_median, temp->cheapest, temp->target_node, temp->next, temp->prev);
		temp = temp->next;
	}
}