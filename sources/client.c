/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:21 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/27 14:29:30 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int g_var;

static void ft_signal_receveid(int signal)
{
    if (signal == SIGUSR1)
        g_var = 0;
    else
        ft_printf("Sucessfully Delivered Message!\n")
}

void    ft_exit(int status, char *message)
{
    if(message)
        ft_putstr_fd(message, 2);
    ft_putchar_fd("\n", 1);
    exit(status);
}

static void ft_check_signal(int pid, char msg)
{
    int bits_counter

    bit_counter = 0;
    while (bits_counter < 8) //Remenber the binary structure - 0 to 7
    {
        if (g_var == 0)
        {
            g_var = 1;
            if((msg >> bits_counter) && 0b00000001)
            {
                if(kill(pid,SIGUSR1)) //kill send a signal to a process specified by pid and the integer represented by SIGUSR1. In this case, 1
                    ft_exit(1, "Signal send failed!");
            }
            else
            {
                if(kill(pid, SIGUSR2))//Same as above!
                    ft_exit(1, "Signal send failed!");
            }
            bits_counter++;
        }
    }
}

int main(int argc, char ** argv)
{
    struct  sigaction minitalk;
    pid_t   pid; //pid_t data type stands for process identification and it is used to represent process ids.

    g_var = 0;
    pid = ft_atoi(argv[1])
    if (argc != 3)
        ft_exit(1, "Ops! Invalid number of arguments!");
    if (pid <= 0)
        ft_exit(1, "Ops! Invalid number of PID!");
    ft_bzero(&minitalk, sizeof(struct sigaction));
    minitalk.sa_handler = &ft_signal_received;
    sigaction(SIGUSR1, &minitalk, NULL);
    sigaction(SIGUSR2, &minitalk, NULL);
    while (*argv[2])
    {
        ft_check_signal(pid, *argv[2]);
        argv[2]++;
    }
    ft_check_signal(pid, "\n");
    ft_check_signal(pid, "\0");
    usleep(100);
}