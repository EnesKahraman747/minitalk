/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:24:27 by sekahram          #+#    #+#             */
/*   Updated: 2022/07/30 15:22:02 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_write_message(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
	{
		c |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID --> %d\n", pid);
	ft_printf("waiting for message...\n");
	while (1)
	{
		signal(SIGUSR1, ft_write_message);
		signal(SIGUSR2, ft_write_message);
		pause();
	}
	return (0);
}
