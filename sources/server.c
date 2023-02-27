/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:33 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/27 14:29:29 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    ft_exit(int status, char *message)
{
    if(message)
        ft_putstr_fd(message, 2);
    ft_putchar_fd("\n", 1);
    exit(status);
}

