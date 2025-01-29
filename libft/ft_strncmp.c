/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:21 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/24 12:24:44 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break ;
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char s1[] = "Bon";
//  	char s2[] = "Bonjour";
//  	printf("%d\n", ft_strncmp(s1, s2, 3));
//  	printf("%d\n", ft_strncmp(s1, s2, 4));
// 	}
