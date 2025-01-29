/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:19:31 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/01/15 11:41:55 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
	{
		return (-1);
	}
	return (1);
}

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
	return (c);
}
