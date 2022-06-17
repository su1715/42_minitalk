/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:32:33 by sujpark           #+#    #+#             */
/*   Updated: 2021/11/29 15:56:17 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = 0;
	i = 0;
	while (i < size)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
		{
			ptr = &((unsigned char *)str)[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
