/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/19 16:51:24 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_wrapping(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_putstr_fd("Error: Lost connection to client(PID: ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putendl_fd(")", 1);
		exit(EXIT_FAILURE);
	}
}

void	write_char(unsigned char character)
{
	if (write(1, &character, 1) < 0)
	{
		ft_putendl_fd("server: Error: Printing client's message failed.", 1);
		exit(EXIT_FAILURE);
	}
}

void	error_exit(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	print_pid(void)
{
	int		pid;

	pid = getpid();
	ft_putstr_fd("My PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putendl_fd("", 1);
}
