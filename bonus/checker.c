/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:45:44 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/12 15:01:32 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_organized(t_stack_node **a)
{
	t_stack_node	*current;

	current = *a;
	while (current && current->next)
	{
		if (current->nbr > current->next->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_and_do(char *command, t_stack_node **a, t_stack_node **b, size_t i)
{
	if (!ft_strncmp("pa", command, i))
		pa(a, b, 0);
	else if (!ft_strncmp("pb", command, i))
		pb(a, b, 0);
	else if (!ft_strncmp("ra", command, i))
		ra(a, 0);
	else if (!ft_strncmp("rb", command, i))
		rb(b, 0);
	else if (!ft_strncmp("rr", command, i))
		rr(a, b, 0);
	else if (!ft_strncmp("rra", command, i))
		rra(a, 0);
	else if (!ft_strncmp("rrb", command, i))
		rrb(b, 0);
	else if (!ft_strncmp("rrr", command, i))
		rrr(a, b, 0);
	else if (!ft_strncmp("sa", command, i))
		sa(a, 0);
	else if (!ft_strncmp("sb", command, i))
		sb(b, 0);
	else if (!ft_strncmp("ss", command, i))
		ss(a, b, 0);
	else
		return (1);
	return (0);
}

void	get_commands(t_stack_node **a, t_stack_node **b, int i)
{
	char	c;
	char	*command;

	command = malloc(5);
	while (read(0, &c, 1))
	{
		if (c == '\n' || i == 4)
		{
			command[i] = '\0';
			if (check_and_do(command, a, b, i + 1))
			{
				free(command);
				ft_putstr_fd("Error\n", 2);
				free_stack(a, del_pointer);
				free_stack(b, del_pointer);
				exit(1);
			}
			i = 0;
		}
		else
			command[i++] = c;
	}
	free(command);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	check_errors(ac, av);
	stack_init(&a, ac, av);
	get_commands(&a, &b, 0);
	if (!stack_organized(&a) && b == NULL)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free_stack(&a, del_pointer);
	free_stack(&b, del_pointer);
	return (0);
}
