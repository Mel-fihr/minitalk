/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:37:56 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 14:12:07 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"
#include <signal.h>

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		c[8];
	static int		i = 0;
	int				res;
	int				j;
	static pid_t	pid_client = 0;

	(void)ucontext;
	res = 0;
	j = 0;
	if (pid_client != info->si_pid)
	{
		ft_bzero(&c, 8);
		i = 0;
		j = 0;
	}
	pid_client = info->si_pid;
	c[i++] = 1 * (sig == SIGUSR1);
	if (i == 8)
	{
		while (j < 8)
			res = res * 2 + c[j++];
		write(1, &res, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
