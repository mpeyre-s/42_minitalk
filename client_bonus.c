/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:07 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/06 14:52:40 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bits_cmp(char c, int i)
{
	return ((c >> i) & 1);
}

int	shutdown(int serv_pid)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if (kill(serv_pid, SIGUSR2) == -1)
			return (-1);
		usleep(500);
		bits--;
	}
	return (0);
}

int	outbox(int server_pid, char *str)
{
	int	i;
	int	bits;

	i = -1;
	while (str[++i])
	{
		bits = 8;
		while (--bits >= 0)
		{
			if (bits_cmp(str[i], bits) == 1)
			{
				if (kill(server_pid, SIGUSR1) == -1)
					return (-1);
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					return (-1);
			}
			usleep(500);
		}
	}
	if (shutdown(server_pid) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("Wrong nb of args"));
	if (outbox(ft_atoi(av[1]), av[2]) == -1)
		return (ft_printf("PID error"));
	return (0);
}
