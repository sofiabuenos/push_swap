/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_sinit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:38:48 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/12 20:19:30 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s <= 9 && *s <= 13))
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
		exit(1);
	}
	return (0);
}

void	bubble_sort(int arr[], int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
