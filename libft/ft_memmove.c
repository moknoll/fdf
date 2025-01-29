/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:48 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/30 08:57:38 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*byte_dest;
	unsigned char	*byte_src;

	i = 0;
	byte_dest = (unsigned char *) dest;
	byte_src = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (byte_dest < byte_src)
	{
		while (i < n)
		{
			byte_dest[i] = byte_src[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			byte_dest[n] = byte_src[n];
		}
	}
	return (dest);
}
