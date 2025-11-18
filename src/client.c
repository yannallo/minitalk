/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:33 by yallo             #+#    #+#             */
/*   Updated: 2023/09/27 14:11:48 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

int	g_flag = 1;

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	size_t	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	send_bi(char symbol, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_flag = 0;
		if (((symbol >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_flag == 0)
			pause();
		usleep(50);
		i--;
	}
}

void	send(char *text, int pid)
{
	if (!text || !*text)
		return ;
	while (*text)
	{
		send_bi(*text, pid);
		text++;
	}
	send_bi('\0', pid);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_flag = 1;
	if (signal == SIGUSR2)
		ft_printf("Your message has been received !!!\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("Use:\n./client \"PID\" \"message\"\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Wrong PID"), 0);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send(argv[2], pid);
	return (0);
}
