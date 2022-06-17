/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:55 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/14 12:17:24 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format(va_list args, const char format, int *len_ptr)
{
	if (format == 'c')
		ft_print_char(va_arg(args, int), len_ptr);
	else if (format == 's')
		ft_print_string(va_arg(args, char *), len_ptr);
	else if (format == 'p')
		ft_print_pointer(va_arg(args, void *), len_ptr);
	else if (format == 'd' || format == 'i')
		ft_print_decimal(va_arg(args, int), len_ptr);
	else if (format == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), len_ptr);
	else if (format == 'X')
		ft_print_hex_upper(va_arg(args, unsigned int), len_ptr);
	else if (format == 'x')
		ft_print_hex(va_arg(args, unsigned int), len_ptr);
	else if (format == '%')
		ft_print_char('%', len_ptr);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
				ft_print_format(args, str[++i], &len);
		}
		else
			ft_print_char(str[i], &len);
		if (len == -1)
			break ;
	}
	va_end(args);
	return (len);
}
