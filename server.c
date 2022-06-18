/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:13:29 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/18 20:30:51 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_sigact(void);

static void	end_receive(pid_t pid)
{
	if (kill(pid, SIGUSR2) < 0)
		if (ft_printf("server: Error: Lost connection to client(PID: %d)\n", pid) < 0)
			exit(EXIT_FAILURE);
	init_sigact();
}

static void receive_msg(int sig, siginfo_t *siginfo, void *context)
{
	static char		character;
	static int		cnt_bit;
	static pid_t	pid;

	(void) context;
	if (!character && !cnt_bit)
		pid = siginfo->si_pid;
	cnt_bit++;
	if (sig == SIGUSR1)
		character &= ~(1 << (8 - cnt_bit));
	else if (sig == SIGUSR2)
		character |= (1 << (8 - cnt_bit));
	if (cnt_bit == 8)
	{
		cnt_bit = 0;
		if (!character)
		{
			write_char('\n');
			end_receive(pid);
			return ;
		}
		write_char(character);
	}
	if (kill(pid, SIGUSR1) < 0)
		if (ft_printf("server: Error: Lost connection to client(PID: %d)\n", pid) < 0)
			exit(EXIT_FAILURE);
}

static void connect(int sig, siginfo_t *siginfo, void *context)
{
	int		client_pid;
	t_sigact	sigact;

	(void) sig;
	(void) context;
	client_pid = siginfo->si_pid;
	if (ft_printf("server: Connect to client(PID: %d)\n", client_pid) < 0)
		exit(EXIT_FAILURE);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = receive_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("server: Error: Sigaction failed its work.");
	if (kill(client_pid, SIGUSR1) < 0)
		if (ft_printf("server: Error: Lost connection to client(PID: %d)\n", client_pid) < 0)
			exit(EXIT_FAILURE);
}

static void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = connect;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("server: Error: Sigaction failed its work.");
}

int main(void)
{
	print_pid(SERVER);
	init_sigact();
	while(1)
		pause();
}
