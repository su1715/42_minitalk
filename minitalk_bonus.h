/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:42:40 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/19 16:53:15 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft.h"
# include <signal.h>

typedef struct sigaction	t_sigact;

typedef struct s_send_info
{
	char	*str;
	pid_t	server_pid;
}				t_send_info;

void	print_pid(void);
void	error_exit(char *str);
void	write_char(unsigned char character);
void	kill_wrapping(pid_t pid, int signal);

#endif
