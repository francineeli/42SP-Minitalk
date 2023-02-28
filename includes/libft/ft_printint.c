/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:06:33 by jdantas-          #+#    #+#             */
/*   Updated: 2023/02/28 13:18:52 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_len(char *s, int n, size_t size)
{
	s[size] = '\0';
	size--;
	if (n >= 0)
	{
		while (size)
		{
			s[size] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
		s[size] = n + '0';
	}
	else
	{
		while (size)
		{
			s[size] = (n % 10) * -1 + '0';
			n = n / 10;
			size--;
		}
		s[size] = '-';
	}
}

int	ft_printint(int nb)
{
	char	*result;
	size_t	size;
	int		t;

	if (nb >= 0)
		size = 1;
	else
		size = 2;
	t = nb / 10;
	while (t)
	{
		size++;
		t = t / 10;
	}
	result = malloc(size + 1);
	if (!result)
		return (0x0);
	nbr_len(result, nb, size);
	ft_printstr(result);
	free (result);
	return (size);
}
