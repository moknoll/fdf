/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:33:50 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/28 12:38:11 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
	{
		return (NULL);
	}
	last = lst;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}
