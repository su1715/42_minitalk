/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:13:29 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/19 16:51:53 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	init_sigact(void);

static void	end_receive(pid_t pid)
{
	kill_wrapping(pid, SIGUSR2);
	init_sigact();
}

static void	receive_msg(int sig, siginfo_t *siginfo, void *context)
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
			write_char('\n');
			end_receive(pid);
			return ;
		}
		write_char(character);
	}
	kill_wrapping(pid, SIGUSR1);
}

static void	connect(int sig, siginfo_t *siginfo, void *context)
{
	int			client_pid;
	t_sigact	sigact;

	(void) sig;
	(void) context;
	client_pid = siginfo->si_pid;
	ft_putstr_fd("Connect to client(PID: ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putendl_fd(")", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = receive_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("Error: Sigaction failed its work.");
	kill_wrapping(client_pid, SIGUSR1);
}

static void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = connect;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("Error: Sigaction failed its work.");
}

int	main(void)
{
	print_pid();
	init_sigact();
	while (1)
		pause();
}
