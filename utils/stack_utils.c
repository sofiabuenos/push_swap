/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:16:19 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/13 17:49:35 by sofiabueno       ###   ########.fr       */
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
