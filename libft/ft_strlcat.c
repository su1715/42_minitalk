/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:32:54 by sujpark           #+#    #+#             */
/*   Updated: 2021/12/19 04:58:47 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (str[len] && len < maxlen)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strnlen(dest, size);
	if (len == size)
		return (len + ft_strlen(src));
	return (len + ft_strlcpy(dest + len, src, size - len));
}
