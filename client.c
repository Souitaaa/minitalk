/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:59:02 by csouita           #+#    #+#             */
/*   Updated: 2024/05/06 22:21:06 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char *str)
{
	int		shift;
	size_t	i;
	int		err;

	i = 0;
	while (str[i])
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				err = kill(pid, SIGUSR1);
			else
				err = kill(pid, SIGUSR2);
			if (err == -1)
			{
				printf("wrong pid\n");
				exit(1);
			}
			shift--;
			usleep(150);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '+')
				i++;
			if (!ft_isdigit(argv[1][i]))
			{
				write(1, "pid is invalid", 15);
				exit(1);
			}
			i++;
		}
		send_bits(ft_atoi(argv[1]), argv[2]);
	}
	else
		write(1, "we only need 3 arguments", 25);
	return (0);
}
