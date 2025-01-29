/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:15:02 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/24 11:36:16 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *) ptr;
	while (n > 0)
	{
		*(byte_ptr++) = (unsigned char) value;
		n--;
	}
	return (ptr);
}
