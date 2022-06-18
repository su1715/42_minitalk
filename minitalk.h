/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:42:40 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/18 22:02:16 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SERVER 1
# define CLIENT 0

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>

typedef struct sigaction	t_sigact;

typedef struct s_send_info
{
	char	*str;
	pid_t	server_pid;
}				t_send_info;

void	print_pid(int is_server);
void	error_exit(const char *str);
void	write_char(char character);
void	kill_wrapping(pid_t pid, int signal);

#endif
