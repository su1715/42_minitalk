/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/16 22:12:16 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		ft_printf("Server PID: %d\n", pid);
	else
		ft_printf("Client PID: %d\n", pid); // 클라이언트 pid 는 표시할 필요 없지 않나?
}
