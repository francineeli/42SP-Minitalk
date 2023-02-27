/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:42:39 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 08:54:45 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*backnode;

	if (new == NULL)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		backnode = ft_lstlast(*lst);
		backnode->next = new;
	}
}
