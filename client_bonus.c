/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:50:16 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/19 16:50:18 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_send_info	g_send_info;

static int	get_bit(void)
{
	static int	char_position = 0;
	static int	bit_order = 0;
	int			bit_position;

	bit_order++;
	if (bit_order > 8)
	{
		char_position++;
		bit_order = 1;
	}
	if (g_send_info.str[char_position])
	{
		bit_position = 1 << (8 - bit_order);
		return (g_send_info.str[char_position] & bit_position);
	}
	return (0);
}

static void	send_char_bit(int sig, siginfo_t *siginfo, void *context)
{
	int	bit;
	int	bit_signal;

	(void) context;
	(void) siginfo;
	bit = get_bit();
	if (sig == SIGUSR1)
	{
		if (!bit)
			bit_signal = SIGUSR1;
		else
			bit_signal = SIGUSR2;
		if (kill(g_send_info.server_pid, bit_signal) < 0)
			error_exit("Send message to server failed.");
	}
	else if (sig == SIGUSR2)
	{
		ft_putendl_fd("Server received full message", 1);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(int sig, siginfo_t *siginfo, void *context)
{
	t_sigact	sigact;
	int			bit;
	int			bit_signal;

	(void) sig;
	(void) context;
	if (siginfo->si_pid != g_send_info.server_pid)
		return ;
	ft_putstr_fd("Connect to server(PID: ", 1);
	ft_putnbr_fd(siginfo->si_pid, 1);
	ft_putendl_fd(")", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_char_bit;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("Error: Sigaction failed its work.");
	bit = get_bit();
	if (!bit)
		bit_signal = SIGUSR1;
	else
		bit_signal = SIGUSR2;
	if (kill(g_send_info.server_pid, bit_signal) < 0)
		error_exit("Send message to server failed.");
}

static void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_message;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("client: Error: Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_exit("Error: Wrong parameters (./client [server PID] [msg])");
	g_send_info.server_pid = ft_atoi(argv[1]);
	g_send_info.str = argv[2];
	print_pid();
	init_sigact();
	if (kill(g_send_info.server_pid, SIGUSR1) < 0)
		error_exit("Error: Connect to server failed.");
	while (1)
		pause();
}
