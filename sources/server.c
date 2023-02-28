/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:33 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/28 15:28:52 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    errors(char *message)
{
   
    ft_putstr_fd(message, STDERR_FILENO); 
    exit(EXIT_FAILURE);
}

void    print_signal(int signal, siginfo_t *info, void *ucontext)
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
                errors("Failed to send signal.\n");    
        }
        letter = 0;
        bits_shifted = 0;
    }
    else
        bits_shifted++;
    if(kill(info->si_pid, SIGUSR1))
        errors("Failed to send signal.\n");
}

int	main(void)
{
	struct sigaction	minitalk;

	ft_bzero(&minitalk, sizeof (struct sigaction)); 
	minitalk.sa_flags = SA_SIGINFO; 
	minitalk.sa_sigaction = print_signal;
	if (sigaction(SIGUSR1, &minitalk, NULL))
		errors("Failed to configure signal function.\n");
	if (sigaction(SIGUSR2, &minitalk, NULL))
		errors("Failed to configure signal function.\n");
	ft_printf("PID: %d\n", (int)getpid());
	while (1)
		pause();
	return (0);
}
