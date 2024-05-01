/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:09:03 by csouita           #+#    #+#             */
/*   Updated: 2024/04/30 17:19:29 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_bits(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
		i++;
	}
	if (sig == SIGUSR2)
	{
		c = (c << 1);
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	signal(SIGUSR1, handle_bits);
	signal(SIGUSR2, handle_bits);
	ft_putstr("PID ");
	ft_putstr(pid);
	free(pid);
	ft_putstr("\n");
	while (1)
	{
	}
	return (0);
}
