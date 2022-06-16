/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:09:19 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/16 21:58:04 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

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
	if (g_info.str[i])
		return (g_info.str[i] & (1 << (8 - recv)));
	return (0);
}

static void	send_char_bit(int sig, siginfo_t *siginfo, void *context)
{
	int	bit;

	// siginfo 통해서 server pid 확인하기
	(void) siginfo; // sigact가 아닌 sig로 처리할 수 있는지 생각해보기
	(void) context;
	bit = get_bit();
	if (sig == SIGUSR2) // 여기에 서버에서 수신했다고 확인 메세지 띄워야하는 것 아닌지? (보너스)
		exit(EXIT_SUCCESS);
	if (sig == SIGUSR1)
	{
		if (!bit)
			kill(g_info.server_pid, SIGUSR1);
		else
			kill(g_info.server_pid, SIGUSR2);
	}
}

static void send_message(int sig, siginfo_t *siginfo, void *context)
{
	t_sigact	sigact;

	ft_printf("client : Connect to server(PID: %d)\n", g_info.server_pid, 1);
	// server랑 연결됐다는것 꼭 적어야하는지?
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_char_bit;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");

	send_char_bit(sig, siginfo, context);
}

static void	init_sigact(void) // static 왜 안넣었던 건지?
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_message;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("client: Error: Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	if (argc != 3) // 꼭 이렇게 자세하게 적어야하는지? 정해진 형식이 있는지?
		error_exit("client: Error: Wrong parameters(./client [server PID] [msg])");
	g_info.server_pid = ft_atoi(argv[1]);
	if (g_info.server_pid < 100 || g_info.server_pid > 99998)
		error_exit("client: Error: Invalid PID");
	g_info.str = (unsigned char *) argv[2];
	print_pid(CLIENT);
	init_sigact();
	kill(g_info.server_pid, SIGUSR1);
	while(1)
		pause();
}
