/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:25:01 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/06 16:00:33 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	cur = *lst;
	if (cur == NULL)
	{
		*lst = new;
		return ;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new;
}
