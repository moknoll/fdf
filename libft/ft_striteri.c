/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:58:50 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/30 09:04:14 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void print_char_with_index(unsigned int index, char *c)
// {
//     printf("Index %u: %c\n", index, *c);
// }

// int main()
// {
//     char str[] = "Hello";
//     ft_striteri(str, print_char_with_index);
//     return 0;
// }
