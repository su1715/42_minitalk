/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:32:29 by sujpark           #+#    #+#             */
/*   Updated: 2021/12/19 05:06:00 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*ptr_c;
	size_t			i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		ptr_c[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
