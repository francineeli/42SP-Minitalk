/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:11:03 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 08:55:45 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*nlst;

	nlst = (t_list *) malloc(sizeof(t_list));
	if (!nlst)
		return (NULL);
	nlst->content = content;
	nlst->next = NULL;
	return (nlst);
}		
