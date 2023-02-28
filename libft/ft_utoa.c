/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:53:55 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/28 13:11:15 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	utoa_len(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_utoa(unsigned int n)
{
	int		size;
	char	*result;

	size = utoa_len(n);
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	result[size] = 0;
	while (size > 0)
	{
		result[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	size = ft_printstr(result);
	free (result);
	return (size);
}