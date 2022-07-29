/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:43:45 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/06 15:38:00 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
