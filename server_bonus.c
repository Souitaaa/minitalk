/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:33:40 by csouita           #+#    #+#             */
/*   Updated: 2024/04/01 17:25:05 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_bits(int sig, siginfo_t *info , void *context)
{
    static int i;
    static char c;
    (void)context;
    if (sig == SIGUSR1) 
        c = (c << 1 )| 1 ;
    else if (sig == SIGUSR2) 
        c = (c << 1);
    i++;
    if (i == 8)
    {
        if (c == '\0')
            kill(info->si_pid,SIGUSR2);
        else
            write(1,&c,1);
            
        i = 0;
        c = 0;
    }
}
int main()
{   
    char *pid ;
    
    struct sigaction    sa;
    sa.sa_sigaction = &handle_bits;
    sa.sa_flags = SA_SIGINFO;
    pid = ft_itoa(getpid());
    ft_putstr("PID ");
    ft_putstr(pid);
    free(pid);
    ft_putstr("\n");
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    while(1)
    {
    }
    return 0;
}
