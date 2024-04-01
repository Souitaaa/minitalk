/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:28:33 by csouita           #+#    #+#             */
/*   Updated: 2024/04/01 17:31:22 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bits(int pid,char str)
{
    int shift;
    shift = 7;
    while (shift >=0)
    {
        if ((str >> shift) & 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        usleep(150);
        shift--;
    }
}
void message(int sig)
{
    (void)sig;
    write(1,"Message sent successfully!",27);
}
int main(int argc, char *argv[])
{
    int i ;
    
    i = 0;
    signal(SIGUSR2,message);
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == '+')
                i++;
            if (!ft_isdigit(argv[1][i]))
            {
                write(1,"pid is invalid",15);
                exit(1);
            }
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            send_bits(ft_atoi(argv[1]),argv[2][i]);
            i++;
        }
        send_bits(ft_atoi(argv[1]),argv[2][i]);
    }
    else 
        write(1,"we only need 3 arguments",25);
    return 0;
}
