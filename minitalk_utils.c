/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/18 19:57:09 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_char(char character)
{
	if (write(1, &character, 1) < 0)
	{
		ft_printf("server: Error: Printing client's message failed.");
		exit(EXIT_FAILURE);
	}
}

void	error_exit(const char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	print_pid(int is_server)
{
	int	pid;

	pid = getpid();
	if (is_server)
	{
		if (ft_printf("Server PID: %d\n", pid) < 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (ft_printf("Client PID: %d\n", pid) < 0)
			exit(EXIT_FAILURE);
	}
}
