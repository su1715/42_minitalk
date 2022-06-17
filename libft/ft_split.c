/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:58:23 by sujpark           #+#    #+#             */
/*   Updated: 2021/12/06 17:38:25 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freearr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int	ft_wdcnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static int	ft_wdlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wdcnt;
	int		wdlen;

	result = (char **)malloc(sizeof(char *) * (ft_wdcnt(s, c) + 1));
	if (!result)
		return (NULL);
	wdcnt = 0;
	while (*s)
	{
		wdlen = 0;
		if (*s != c)
		{
			wdlen = ft_wdlen(s, c);
			result[wdcnt] = (char *)malloc(sizeof(char) * (wdlen + 1));
			if (!result[wdcnt])
				return (ft_freearr(result, wdcnt));
			ft_strlcpy(result[wdcnt++], (char *)s, wdlen + 1);
		}
		s += wdlen;
		if (*s)
			s++;
	}
	result[wdcnt] = NULL;
	return (result);
}
