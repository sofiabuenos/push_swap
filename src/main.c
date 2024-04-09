/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:00:53 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/08 15:25:02 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	check_errors(ac, av);
	stack_init(&a, ac, av);
	// int len = stack_len(&a);
	// int i = 0;
	// int *arr = get_median(&a, stack_len(&a));
	// while (i < len)
	// {
	// 	printf("arr[%d] = %d\n", i, arr[i]);
	// 	i++;
	// }
	//printf("mediana é: %d", get_median(&a, stack_len(&a)));
	//printstack(&b, 'b');
	sort_stack(&a, &b);
	printstack(&a, 'a');
	return (0);
}
