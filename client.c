/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:09:19 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/18 20:16:47 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_send_info	g_send_info;

static int	get_bit(void)
{
	static int	i = 0;
	static int	recv = 0;

	recv++;
	if (recv > 8)
	{
		i++;
		recv = 1;
	}
	if (g_send_info.str[i])
		return (g_send_info.str[i] & (1 << (8 - recv)));
	return (0);
}

static void	send_char_bit(int sig, siginfo_t *siginfo, void *context)
{
	int	bit;
	int bit_signal;

	(void) context;
	if (siginfo->si_pid != g_send_info.server_pid)
		return;
	bit = get_bit();
	if (sig == SIGUSR2)
	{
		if (ft_printf("client: Server received full message\n") < 0)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR1)
	{
		if (!bit)
			bit_signal = SIGUSR1;
		else
			bit_signal = SIGUSR2;
		if (kill(g_send_info.server_pid, bit_signal) < 0)
			error_exit("client: Send message to server failed.");
	}
}

static void send_message(int sig, siginfo_t *siginfo, void *context)
{
	t_sigact	sigact;

	if (siginfo->si_pid != g_send_info.server_pid)
		return;
	if (ft_printf("client: Connect to server(PID: %d)\n", g_send_info.server_pid, 1) < 0)
		exit(EXIT_FAILURE);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_char_bit;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("client: Erro: Sigaction failed its work.");

	send_char_bit(sig, siginfo, context);
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
		error_exit("client: Error: Wrong parameters(./client [server PID] [msg])");
	g_send_info.server_pid = ft_atoi(argv[1]);
	if (g_send_info.server_pid < 100 || g_send_info.server_pid > 99998)
		error_exit("client: Error: Invalid PID");
	g_send_info.str = (unsigned char *) argv[2];
	print_pid(CLIENT);
	init_sigact();
	if (kill(g_send_info.server_pid, SIGUSR1))
		error_exit("client: Error: Signal to server failed.");
	while(1)
		pause();
}
