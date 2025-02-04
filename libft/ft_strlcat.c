/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:28:11 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/23 11:28:41 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = 0;
	dest_len = 0;
	while (dest[dest_len] && dest_len < n)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (n <= dest_len)
		return (n + src_len);
	while (src[i] && (dest_len + i) < (n - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if ((dest_len + i) < n)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
