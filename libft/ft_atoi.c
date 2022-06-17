/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:44:11 by sujpark           #+#    #+#             */
/*   Updated: 2021/12/19 19:01:29 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str++ - '0';
		if (sign == 1 && result > 9223372036854775807L)
			return (-1);
		if (sign == -1 && result > 9223372036854775808UL)
			return (0);
	}
	return ((int)result * sign);
}
