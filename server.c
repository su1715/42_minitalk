/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:13:29 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/16 21:22:09 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_sigact(void);

static void	end_receive(pid_t pid)
{
	kill(pid, SIGUSR2);
	init_sigact();
}

static void receive_msg(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	character;
	static int				cnt_bit;
	static pid_t			pid;

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
			write(1, "\n", 1);
			end_receive(pid);
			return ;
		}
		write(1, &character, 1);
	}
	kill(pid, SIGUSR1);
}

static void connect(int sig, siginfo_t *siginfo, void *context)
{
	int		client_pid;
	t_sigact	sigact;

	(void) sig;
	(void) context;
	client_pid = siginfo->si_pid;
	ft_printf("server: Connect to client(PID: %d)\n", client_pid);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = receive_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("server: Error: Sigaction failed its work.");
	kill(client_pid, SIGUSR1);
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
