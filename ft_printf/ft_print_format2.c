/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:18:45 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/14 12:02:05 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_itoa(int n)
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

void	ft_print_decimal(int num, int *len_ptr)
{
	char	*str;

	str = ft_itoa(num);
	ft_print_string(str, len_ptr);
	free(str);
}

void	ft_print_unsigned(unsigned int num, int *len_ptr)
{
	if (num >= 10)
		ft_print_unsigned(num / 10, len_ptr);
	num %= 10;
	ft_print_char("0123456789"[num], len_ptr);
}
