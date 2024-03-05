/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <namrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:29:00 by namrene           #+#    #+#             */
/*   Updated: 2024/03/03 22:47:25 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_dcml(char *s)
{
	char	result;
	int		i;

	result = 0;
	i = 7;
	while (i >= 0)
	{
		result |= (s[i] - '0') << (7 - i);
		i--;
	}
	write(1, &result, 1);
}

void	bit_hdlr(int sig, siginfo_t *info, void *context)
{
	static int		i = 0;
	static char		c[8];
	static pid_t	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		i = 0;
		ft_memset(c, 0, sizeof(c));
	}
	pid = info->si_pid;
	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		conv_dcml(c);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	sa.sa_sigaction = bit_hdlr;
	sa.sa_flags = SA_SIGINFO;
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		write(1, "\n", 1);
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
