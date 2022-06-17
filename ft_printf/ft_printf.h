/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:24:27 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/14 12:03:52 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_char(char c, int *len_ptr);
void	ft_print_string(char *str, int *len_ptr);
void	ft_print_decimal(int num, int *len_ptr);
void	ft_print_unsigned(unsigned int num, int *len_ptr);
void	ft_print_hex_upper(size_t num, int *len_ptr);
void	ft_print_hex(size_t num, int *len_ptr);
void	ft_print_pointer(void *ptr, int *len_ptr);

#endif
