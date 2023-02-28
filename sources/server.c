/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:33 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/28 13:53:34 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

void    ft_exit(int status, char *message)
{
    if(message)
        ft_putstr_fd(message, 2); //putstr_fd prints string s in the fd. No return value
    ft_putchar_fd('\n', 1); // putchar_fd prints char c in the fd. No return value
    exit(status);
}

static  void    ft_print_signal(int signal, siginfo_t *info, void *ucontext)
{
    static int bits_shifted;
    static char letter;

    (void)ucontext;
    if(signal == SIGUSR1)
        letter += (0b00000001 << bits_shifted);
    if(bits_shifted == 7)
    {
        if(letter)
            ft_putchar_fd(letter, 1);
        else
        {
            if(kill(info->si_pid, SIGUSR2))
                ft_exit(1, "Signal send failure");    
        }
        letter = 0;
        bits_shifted = 0;
    }
    else
        bits_shifted++;
    if(kill(info->si_pid, SIGUSR1))
        ft_exit(1, "Signal send failure");
}

int	main(void)
{
	struct sigaction	minitalk;

	ft_bzero(&minitalk, sizeof (struct sigaction)); 
	minitalk.sa_flags = SA_SIGINFO; 
	minitalk.sa_sigaction = ft_print_signal;
	if (sigaction(SIGUSR1, &minitalk, NULL))
		ft_exit(1, "Failed to configure signal function");
	if (sigaction(SIGUSR2, &minitalk, NULL))
		ft_exit(1, "Failed to configure signal function");
	ft_printf("PID: %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
