/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:49:46 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 08:57:14 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		len;
	char		*d;
	const char	*s;

	len = 0;
	d = (char *) dst;
	s = (const char *) src;
	while (len < n)
	{
		d[len] = s[len];
		len++;
	}
	return (dst);
}
