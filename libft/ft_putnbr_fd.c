/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:59:28 by sujpark           #+#    #+#             */
/*   Updated: 2021/11/29 15:16:19 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_digit(int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_print_digit(n / 10, fd);
		ft_print_digit(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = -147483648;
		}
		n = -n;
	}
	ft_print_digit(n, fd);
}
