/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:54:33 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:15 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_counter(int sig, siginfo_t *info, void *context)
{
	static unsigned int	received = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	ft_send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

static void	error_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("Error: Try ./client [PID] [\"MESSAGE\"]\n", 2);
		exit (0);
	}
	while ((argv[1][i]) != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd("Error: Invalid server PID\n", 2);
			exit (0);
		}
		i++;
	}
	if (kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_putstr_fd("Error: Invalid server PID\n", 2);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	error_check(argc, argv);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_counter;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
