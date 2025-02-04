/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:27:45 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/22 11:09:04 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	if (n > 0)
	{
		while (src[i] && (i < n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
