/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:49:09 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/03 17:39:43 by sbueno-s         ###   ########.fr       */
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

// int	*stack_toarr(t_stack_node **a)
// {
// 	int				arr;
// 	int				arr_len;
// 	int				i;
// 	t_stack_node	*current;

// 	if (stack_len(a) == 0)
// 		return (0);
// 	arr_len = stack_len(a);
// 	arr = ft_calloc(arr, sizeof(int));
// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	current = *a;
// 	while (current)
// 	{
// 		arr[i] = current->nbr;
// 		current = current->next;
// 		i++;
// 	}
// 	return(arr);
//}

int get_next_min(t_stack_node **a, int *selected, int len)
{
    t_stack_node *current = *a;
    t_stack_node *smaller = NULL;
    int i;

    while (current)
    {
        // Verifica se o número atual já foi selecionado
        for (i = 0; i < len; i++)
        {
            if (current->nbr == selected[i])
                break;
        }
        // Se o número atual não foi selecionado e é menor que o menor encontrado até agora
        if (i == len && (smaller == NULL || current->nbr < smaller->nbr))
        {
            smaller = current;
        }
        current = current->next;
    }
    if (smaller)
    {
        printf("prox min: %ld\n", smaller->nbr);
        return (smaller->nbr);
    }
    else
    {
        printf("Nenhum próximo mínimo encontrado.\n");
        return INT_MAX; // Retorna um valor inválido se não houver próximo mínimo
    }
}


int organize_arr(t_stack_node **a, int len)
{
    int *org_arr;
    int i;
    int min;
	int median;
    int *selected = malloc(len * sizeof(int)); // Array para armazenar números já selecionados

    if (!selected)
        return 0; // Verifica se a alocação foi bem-sucedida

    org_arr = ft_calloc(len, sizeof(int));
    if (!org_arr)
    {
        free(selected); // Libera a memória alocada para selected
        return 0;
    }

    min = (return_smallest(a))->nbr;
    org_arr[0] = min;
    selected[0] = min; // Marca o número mínimo como selecionado
    i = 1;
    while (i < len)
    {
        org_arr[i] = get_next_min(a, selected, i);
        if (org_arr[i] == INT_MAX) // Se INT_MAX foi retornado, não há próximo mínimo
            break;
        selected[i] = org_arr[i]; // Marca o número selecionado
        i++;
    }
	median = org_arr[len / 2];
    free(selected); // Libera a memória alocada para selected
    return median;
}
