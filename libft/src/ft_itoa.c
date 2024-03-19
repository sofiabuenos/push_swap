/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:26 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/03/01 17:08:07 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_countnum(long int n)
{
	int	count;

	count = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count ++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			numlen;
	long int	nb;

	nb = n;
	numlen = ft_countnum(nb);
	num = ft_calloc(numlen + 1, sizeof(char));
	if (!num)
		return (NULL);
	num[numlen] = '\0';
	if (nb == 0)
		num[0] = '0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		num[--numlen] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (num);
}
/* int	main(void)
{
	printf("%s", ft_itoa());
} */
