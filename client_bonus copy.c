/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:15:44 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 14:15:28 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_sig(pid_t pid, int sig)
{
	if (sig == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

int	bainerer(int c, pid_t pid)
{
	int	i;
	int	res[32];

	i = 0;
	while (i < 32)
	{
		res[31 - i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 0;
	while (i < 32)
	{
		send_sig(pid, res[i]);
		i++;
	}
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message received by server\n", 27);
	}
}

int	main(int ac, char **av)
{
	pid_t			pid;
	unsigned char	*str;

	(void)ac;
	if (ac != 3 || ft_atoi((unsigned char *)av[1]) == -1
		|| ft_atoi((unsigned char *)av[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pid = ft_atoi((unsigned char *)av[1]);
	str = (unsigned char *)av[2];
	signal(SIGUSR1, handler);
	while (*str)
	{
		bainerer(*str, pid);
		str++;
	}
	if (!(*str))
		bainerer(*str, pid);
	sleep(1);
	return (0);
}
