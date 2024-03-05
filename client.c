/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <namrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:28:49 by namrene           #+#    #+#             */
/*   Updated: 2024/03/03 22:45:22 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_bin(char *str, int pid)
{
	int		i;
	int		basebin;
	char	premlettre;

	i = 0;
	while (str[i])
	{
		basebin = 128;
		premlettre = str[i];
		while (basebin > 0)
		{
			if (premlettre >= basebin)
			{
				kill(pid, SIGUSR1);
				premlettre = premlettre - basebin;
			}
			else
				kill(pid, SIGUSR2);
			basebin = basebin / 2;
			usleep(300);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "erreur", 6);
			exit(1);
		}
		convert_bin(argv[2], pid);
	}
	else
		return (-1);
	return (0);
}
