/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:02:59 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/28 09:55:33 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;

	i = 0;
	new_string = (char *)malloc(ft_strlen(s) + 1);
	if (!new_string)
	{
		return (NULL);
	}
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
