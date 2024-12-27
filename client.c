/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:07 by mathispeyre       #+#    #+#             */
/*   Updated: 2024/12/27 18:00:35 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	outbox(int server_pid, char *str)
{
	ft_printf("Server PID : %d, Message : %s\n", server_pid, str);
	ft_printf("Abort... Not internet connection :/");
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (ft_printf("Wrong nb of args"));
	if (outbox(ft_atoi(av[1]), av[2]) == -1)
		return (ft_printf("Erreur au niveau du pid"));
	return (0);
}
