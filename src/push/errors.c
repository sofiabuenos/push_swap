/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:01:01 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/03/27 15:05:05 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief checks if the argument passed is in a number format.
 * Verifica se o primeiro char não é um sinal ou um número. 
 * Depois checa se é um sinal mas o próximo não é.
 * Continua a verificar, até ao ultimo elemento se é um char válido, isto é, um número.
 * @param str_n 
 * @return int 
 */
int syntax_check(int ac, char **av)
{
	int i;
	char *str_n;

	i = 1;
	while (i < ac) 
	{
		str_n = av[i];
		if (!(*str_n == '+' || *str_n == '-' || ft_isdigit(*str_n)))
			return 1; // Erro de sintaxe
		if ((*str_n == '+' || *str_n == '-') && (!ft_isdigit(str_n[1])))
			return (1); // Erro de sintaxe
		while (*++str_n) 
		{
			if (!ft_isdigit(*str_n))
				return (1); // Erro de sintaxe
		}
		i++;
	}
	return (0); // Nenhum erro de sintaxe encontrado
}

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

int	limits_check(long *arr, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	nb_repeats(long *arr,int ac)
{
	int	i, j;

	i = 0;
	while(i < ac -1)
	{
		j = i + 1;
		while (j < ac -1)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	already_sorted(long *arr, int ac)
{
	int	i;
	i = 0;
	while(i < ac -2)
	{
		if(arr[i] > arr [i + 1])
			return (0); // o certo é nao estar ordenado
		i++;
	}
	return (1); // se já está ordenado n faço nada
}
int check_and_free(long *arr, int error)
{
	if (error)
	{
		free(arr); // Libera a memória alocada
		ft_putstr_fd("Error\n", 2); // ft_putstr_fd("Error\n", 2); TEM QUE SER ISSO!
		exit (1);
	}
	return (0); // Retorna 0 indicando que não houve erro
}

int check_errors(int ac, char **av)
{
	long *arr = ft_calloc(ac - 1, sizeof(long));
	if (!arr)
		return (1);
	if (syntax_check(ac, av))
		return check_and_free(arr, 1);
	list_array(arr, ac, av);
	if (limits_check(arr, ac))
		return check_and_free(arr, 1);
	if (nb_repeats(arr, ac))
		return check_and_free(arr, 1);
	if (already_sorted(arr, ac))
		return check_and_free(arr, 1);
	free(arr); // Libera a memória no final, caso não haja erros
	return (0);
}
