/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:16:19 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/03 16:28:01 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s <= 9 && *s <= 13))    // faz sentido fazer essa verificação?
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

// int	main(void)
// {
// 	char *s = "-2147483648";
// 	printf("%ld", ft_atol(s));
// 	return (0);
// }


t_stack_node *return_biggest(t_stack_node **stack)
{
	t_stack_node *current;
	t_stack_node *bigger;

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

t_stack_node *return_smallest(t_stack_node **stack)
{
	t_stack_node *current;
	t_stack_node *smaller;

	if (!stack)
		return (NULL);
	current = *stack;
	smaller = current;
	while (current != NULL)
	{
		if(smaller->nbr > current->nbr)
			smaller = current;
		current = current->next;
	}
	return (smaller);
}
/**
 * @brief APENAS PARA CHECAR - PODE DELETAR DEPOIS
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