/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:41:36 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 09:01:33 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen (s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	result = ft_substr(s1, 0, len + 1);
	return (result);
}
