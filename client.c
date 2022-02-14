/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:54 by syolando          #+#    #+#             */
/*   Updated: 2022/02/14 21:32:30 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"
#include <signal.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>



int	g_all_bits = 0;

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
	while(str[i])
	{
		send_byte(str[i], pid);
		i++;
	}
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


//The sigaction() system call is used to change 
//the action taken by a process on receipt of a specific signal.
/*
struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
*/



int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					server_pid;
	//char	*msg;
	if (argc != 3)
	{
		write(1, "wrong input!\n", 14);
		return (0);
	}
	/*
	 If SA_SIGINFO is specified in sa_flags, then sa_sigaction
       (instead of sa_handler) specifies the signal-handling function
       for signum.  This function receives three arguments, as described
       below.
	*/
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		fatal("SIGUSR1 failure");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		fatal("SIGUSR2 failure");
	server_pid = ft_atoi(argv[1]);
	send_message(argv[2], server_pid); // send_message(copy(argv[2]), server_pid);
	send_message(0, server_pid);
	return (0);
}