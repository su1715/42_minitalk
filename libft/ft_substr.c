/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:06:40 by sujpark           #+#    #+#             */
/*   Updated: 2021/12/06 18:00:36 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*substr;

	j = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	s = s + start;
	while (*s)
	{
		if (j < len)
		{
			substr[j] = *s;
			j++;
		}
		s++;
	}
	substr[j] = '\0';
	return (substr);
}
