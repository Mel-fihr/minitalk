/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:10:18 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/07 14:17:11 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	handle_overflow(long *res, char str)
{
	if (*res > 922337203685477580 || (*res == 922337203685477580
			&& str - 48 > 7))
	{
		return (0);
	}
	*res *= 10;
	*res += str - 48;
	return (1);
}

int	ft_atoi(const unsigned char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if (!handle_overflow(&res, str[i]))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (res *= sign, res);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n > 0)
	{
		*(p++) = 0;
		n--;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			ft_putchar_fd(n + 48, fd);
		}
	}
}
