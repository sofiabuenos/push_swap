/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:01:01 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/04/12 17:17:50 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_errors_checker(int ac, char **av)
{
	long	*arr;

	arr = ft_calloc(ac - 1, sizeof(long));
	if (!arr)
		return (1);
	if (syntax_check(ac, av))
		return (check_and_free(arr, 1));
	list_array(arr, ac, av);
	if (limits_check(arr, ac))
		return (check_and_free(arr, 1));
	if (nb_repeats(arr, ac))
		return (check_and_free(arr, 1));
	free(arr);
	return (0);
}
