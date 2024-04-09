/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:45:44 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/09 20:58:00 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_and_do()

int main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	check_errors_bonus(ac, av);
	stack_init(&a, ac, av);
	return (0);
}
