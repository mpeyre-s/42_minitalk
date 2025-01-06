/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:47 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/06 14:46:17 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_character(char c, char **msg, int *len)
{
	char	*new_msg;

	if (c == '\0')
	{
		ft_printf("%s\n", *msg);
		free(*msg);
		*msg = NULL;
		*len = 0;
	}
	else
	{
		new_msg = (char *)malloc(*len + 2);
		if (!new_msg)
			exit(1);
		ft_memcpy(new_msg, *msg, *len);
		free(*msg);
		new_msg[*len] = c;
		new_msg[*len + 1] = '\0';
		*msg = new_msg;
		(*len)++;
	}
}

void	handle_signal(int signal)
{
	static char		c = 0;
	static int		bit_count = 0;
	static char		*msg = NULL;
	static int		len = 0;

	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		handle_character(c, &msg, &len);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("PID : %d\n", getpid());
	ft_printf("Waiting for signal ...\n");
	while (1)
		pause();
}
