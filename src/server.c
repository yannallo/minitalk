/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:38:03 by yallo             #+#    #+#             */
/*   Updated: 2023/09/27 13:06:32 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	binary = 0;
	char		received;

	binary = binary << 1;
	if (signal == SIGUSR1)
		binary = binary | 1;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		received = (char)binary;
		binary = 0;
		if (received == '\0')
		{
			received = '\n';
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &received, 1);
	}
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Use: No argument\n./server\n"), 0);
	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
