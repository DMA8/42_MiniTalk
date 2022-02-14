/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:59 by syolando          #+#    #+#             */
/*   Updated: 2022/02/14 20:46:08 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"
#include <stdio.h>




void	handler(int signum, siginfo_t *info, void *unused)
{
	static char	result = 0;
	static int	counter = 128;
	static int	bit_order = 0;

	(void)unused;
	if (signum == SIGUSR2)
	{
		result += counter;
		counter = counter >> 1;
		if (kill(info->si_pid, SIGUSR2) == -1)
			fatal("Couldn't send SIGUSR1 back to client\n");
	}
	else if (signum == SIGUSR1)
	{
		counter = counter >> 1;
		if (kill(info->si_pid, SIGUSR1) == -1)
			fatal("Couldn't send SIGUSR2 back to client\n");
	}
	if (++bit_order == 8)
	{
		bit_order = 0;
		counter = 128;
		write(1, &result, 1);
		result = 0;
	}
}


int	main(int argc, char **argv)
{
	struct sigaction	sa;
	
	write(1, "PID: \n", 7);
	ft_putnbr(getpid());
	write(1, "\n", 2);
	sa.sa_flags = SA_SIGINFO;

	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask); // cбрасывает структуру сигакт
	sigaddset(&sa.sa_mask, SIGUSR1); // добавляет сигнал 
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause(); //sleep vs pause learn!
}