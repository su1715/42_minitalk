/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:29:32 by sujpark           #+#    #+#             */
/*   Updated: 2021/11/29 14:44:58 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_len(int n)
{
	int	temp;
	int	len;

	temp = n;
	len = 0;
	if (n < 0)
		len = 1;
	while (temp / 10)
	{
		len++;
		temp /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = ft_digit_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[len--] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (n / 10)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	res[len--] = n + '0';
	return (res);
}
