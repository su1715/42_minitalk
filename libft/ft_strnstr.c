/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:31:22 by sujpark           #+#    #+#             */
/*   Updated: 2021/11/20 16:33:31 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*substr)
		return ((char *)str);
	while (i < len && str[i])
	{
		if (str[i] == substr[0])
		{
			j = 0;
			while (str[i + j] && substr[j]
				&& str[i + j] == substr[j] && i + j < len)
				j++;
			if (!substr[j])
				return (&((char *)str)[i]);
		}
		i++;
	}
	return (NULL);
}
