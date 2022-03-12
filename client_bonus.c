/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:54 by syolando          #+#    #+#             */
/*   Updated: 2022/02/15 18:13:32 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	g_all_bits = 0;

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	handler(int signum, siginfo_t *info, void *unused)
{
	int	a;

	a = info->si_pid;
	(void)unused;
	(void)signum;
	g_all_bits++;
	usleep(500);
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(str[i], pid);
		i++;
	}
	send_byte(0, pid);
}

void	send_byte(char c, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
		{
			if (kill(pid, SIGUSR2))
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR1))
				exit(0);
		}
		usleep(500);
		j--;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					server_pid;

	if (argc != 3)
	{
		write(1, "wrong input!\n", 14);
		return (0);
	}
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		fatal("SIGUSR1 failure");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		fatal("SIGUSR2 failure");
	if (!is_numeric(argv[1]))
	{
		write(1, "bad pid\n", 9);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(argv[2], server_pid);
	ft_putnbr(g_all_bits);
	write(1, " bits were transmitted\n", 24);
	return (0);
}
