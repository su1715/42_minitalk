/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:30:56 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/14 11:47:28 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_upper(size_t num, int *len_ptr)
{
	if (num >= 16)
		ft_print_hex_upper(num / 16, len_ptr);
	num %= 16;
	ft_print_char("0123456789ABCDEF"[num], len_ptr);
}

void	ft_print_hex(size_t num, int *len_ptr)
{
	if (num >= 16)
		ft_print_hex(num / 16, len_ptr);
	num %= 16;
	ft_print_char("0123456789abcdef"[num], len_ptr);
}

void	ft_print_pointer(void *ptr, int *len_ptr)
{
	size_t	num;

	num = (size_t)ptr;
	ft_print_string("0x", len_ptr);
	ft_print_hex(num, len_ptr);
}
