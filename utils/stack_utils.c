/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:16:19 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/05 17:02:27 by sofiabueno       ###   ########.fr       */
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

void	list_array(long *arr, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		arr[i] = ft_atol(av[i + 1]);
		i++;
	}
}

int	check_and_free(long *arr, int error)
{
	if (error)
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (0);
}
void bubble_sort(int arr[], int len)
{
    int i = 0;
    while (i < len - 1)
    {
        int j = 0;
        while (j < len - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                // troca arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int get_median(t_stack_node **a, int len)
{
    int *arr;
    int i;
    int median;
    t_stack_node *current = *a;

    arr = ft_calloc(len, sizeof(int)); // Array para armazenar números da pilha
    if (!arr)
        return (0); // Verifica se a alocação foi bem-sucedida
    // Copia números da pilha para o array
	i = 0;
    while (i < len)
    {
        arr[i] = current->nbr;
        current = current->next;
		i++;
    }
    // Ordena o array usando Bubble Sort
    bubble_sort(arr, len);
    // Calcula a mediana
    median = arr[len / 2];
    free(arr); // Libera a memória alocada para arr
    return median;
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