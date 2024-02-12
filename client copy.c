/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:03:45 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 14:13:11 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int	res[8];

	i = 0;
	while (i < 8)
	{
		res[7 - i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		send_sig(pid, res[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	(void)ac;
	if (ac != 3 || ft_atoi((const char *)av[1]) == -1
		|| ft_atoi((const char *)av[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	while (*str)
	{
		bainerer(*str, pid);
		str++;
	}
	return (0);
}
