/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/18 22:04:38 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_wrapping(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
		if (ft_printf("Error: Lost connection to client(PID: %d)\n", pid) < 0)
			exit(EXIT_FAILURE);
}

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
	int		pid;
	char	*str;

	pid = getpid();
	if (is_server)
		str = "Server";
	else
		str = "Client";
	if (ft_printf("%s PID: %d\n", str, pid) < 0)
		exit(EXIT_FAILURE);
}
