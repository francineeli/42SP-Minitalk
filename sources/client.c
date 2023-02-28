/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:21 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/28 15:29:55 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/libft/libft.h"

int g_var;

void	signal_received(int signal)
{
    if (signal == SIGUSR1)
        g_var = 0;
    else
        ft_printf("Message sent sucessfully!\n");
}

void    errors(char *message)
{
    ft_putstr_fd(message, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

int	check_args(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	check_signal(int pid, char msg)
{
    int bits_counter;

    bits_counter = 0;
    while (bits_counter < 8) 
    {
        if (g_var == 0)
        {
            g_var = 1;
            if((msg >> bits_counter) & 0b00000001)
            {
                if(kill(pid,SIGUSR1)) 
                    errors("Failed to send signal.\n");
            }
            else
            {
                if(kill(pid, SIGUSR2))
                    errors("Failed to send signal.\n");
            }
            bits_counter++;
        }
    }
}

int main(int argc, char ** argv)
{
    struct  sigaction minitalk;
    pid_t   pid; 
    
    if (argc != 3)
        errors("Invalid number of arguments!");
    if (ft_strlen(argv[1]) > 7 || check_args(argv[1])) 
        errors("Invalid PID!");
     pid = ft_atoi(argv[1]);
    ft_bzero(&minitalk, sizeof(struct sigaction));
    minitalk.sa_handler = &signal_received;
    sigaction(SIGUSR1, &minitalk, NULL);
    sigaction(SIGUSR2, &minitalk, NULL);
    while (*argv[2])
    {
        check_signal(pid, *argv[2]);
        argv[2]++;
    }
    check_signal(pid, '\n');
    check_signal(pid, '\0');
    usleep(100);
}