/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:29:49 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/03/01 17:08:07 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	strl[2];

	strl[0] = ft_strlen(src);
	strl[1] = ft_strlen(dst);
	i = strl[1];
	if (size != 0)
	{
		j = 0;
		while (i < size - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (size <= strl[1])
		return (size + strl[0]);
	else
		return (strl[0] + strl[1]);
}
/* int	main(void)
{
	//printf("%d\n", strlcat("sofia ", " buenos", 0));
	printf("%ld\n", ft_strlcat("sofia ", " buenos", 0));
	return (0);
} */