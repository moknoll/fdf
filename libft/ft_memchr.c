/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:18:23 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/30 08:44:18 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		*char_s;

	char_s = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == (char)c)
		{
			return ((void *)(char_s + i));
		}
		i++;
	}
	return (NULL);
}
int main()
{
    char array[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    char* result = ft_memchr(array, 'o', sizeof(array));
    char* result2 = memchr(array, 'o', sizeof(array));

    printf("%s\n", result);
    printf("%s", result2);
}
