/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:49:09 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/20 16:50:30 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*new_node(long n)
{
	t_stack_node *new;

	new = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->nbr = n;
	//  printf("nbr: %ld\n index: %d\n push_cost: %d \n above_median: %d\n cheapest: %d\n"
	// 	"target: %p\n next: %p\n perv: %p\n OUTRA\n\n", new->nbr, new->index, new->push_cost,
	// 	new->above_median, new->cheapest, new->target_node, new->next, new->prev);
	return (new);
}
void	lstadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node *temp; 
	
	if (!stack || !new)
		return ;
	temp = *stack;
	if (!temp) 
	{
		*stack = new;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
}
/**
 * @brief APENAS PARA CHECAR - PODE DELETAR DEPOIS
 * 
 * @param stack 
 * @param c 
 */
#include <stdio.h>

void	printstack(t_stack_node **stack, char c)
{
	t_stack_node *temp = *stack;

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
void	stack_init(t_stack_node **stack, int ac, char **av)
{
	int	i;

	i = 1;
	*stack = new_node(ft_atol(av[1]));
	while (++i < ac)
		lstadd_back(stack, new_node(ft_atol(av[i])));
}
