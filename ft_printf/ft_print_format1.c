/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:19:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/14 11:59:41 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_print_char(char c, int *len_ptr)
{
	int	len;

	if (*len_ptr < 0)
		return ;
	len = write(1, &c, 1);
	if (len < 0)
		*len_ptr = -1;
	else
		*len_ptr += len;
}

void	ft_print_string(char *str, int *len_ptr)
{
	int	len;

	if (*len_ptr < 0)
		return ;
	if (str == 0)
		str = "(null)";
	len = write(1, str, ft_strlen(str));
	if (len < 0)
		*len_ptr = -1;
	else
		*len_ptr += len;
}
