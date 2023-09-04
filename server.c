/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:11:55 by akunegel          #+#    #+#             */
/*   Updated: 2023/07/31 14:48:01 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bitshift(int signal)
{
	static int	i;
	static int	bits;

	if (signal == SIGUSR1)
		i |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		bits = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Do this instead: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Server PID is %d\n", pid);
	ft_printf("Waiting for messages\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_bitshift);
		signal(SIGUSR2, ft_bitshift);
		pause ();
	}
	return (0);
}
