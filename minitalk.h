/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:42:40 by sujpark           #+#    #+#             */
/*   Updated: 2022/06/16 22:11:10 by sujpark          ###   ########.fr       */
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
// 반드시 이렇게 해야하는 것인지?
// sigact 공부하기

typedef struct s_info // 이름 고민
{
	unsigned char	*str; //unsigned char 로 받아야하는 이유는 unicode 때문인가?
	pid_t			server_pid; // 얘를 꼭 전역 변수로 해야하는 이유
}				t_info;

void	print_pid(int is_server);
void	error_exit(const char *str);

#endif

// 보너스 : 유니코드 그냥도 가능한 이유?
// printf 에러(-1)인 경우 처리
// signal 과 sigaction 공부하기
// kill 에러처리 => pid 확인
// print 에러났을때 한번정도는 에러출력 시도 해볼만 하다(by. jaham)
// 프린트 에러 ? 그냥 종료 시켜버려 ^^
