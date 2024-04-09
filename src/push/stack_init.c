/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:49:09 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/09 17:17:39 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*new_node(long n)
{
	t_stack_node	*new;

	new = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->nbr = n;
	return (new);
}

void	lstadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*temp;

	if (!stack || !new)
		return ;
	temp = *stack;
	if (!temp)
	{
		*stack = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
}

void	stack_init(t_stack_node **stack, int ac, char **av)
{
	int	i;

	i = 1;
	*stack = new_node(ft_atol(av[1]));
	while (++i < ac)
		lstadd_back(stack, new_node(ft_atol(av[i])));
}

void	del_pointer(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
void	free_stack(t_stack_node **stack, void (*del)(void*))
{
	t_stack_node *current;
	t_stack_node *temp;

	current = *stack;
	if (!*stack || !del)
		return ;
	while(current)
	{
		temp = current->next;
		del_pointer(current);
		current = temp;
	}
}
