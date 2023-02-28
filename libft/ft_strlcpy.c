/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:25:42 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/28 11:09:12 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	srcsize;

	d = 0;
	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize > 0)
	{
		while (src[d] != '\0' && d < (dstsize -1))
		{
			dst[d] = src[d];
			d++;
		}
		dst[d] = '\0';
	}	
	return (srcsize);
}
