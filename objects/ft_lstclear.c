/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:00:59 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 08:52:56 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clean;

	while (*lst != NULL)
	{
		clean = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clean;
	}
	*lst = NULL;
}
