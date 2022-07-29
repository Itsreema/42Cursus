/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:30:01 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/06 15:18:54 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		new = *lst;
		*lst = (*lst)->next;
		ft_lstdelone (new, del);
	}
}
