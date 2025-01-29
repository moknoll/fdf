/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:43:02 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/23 11:07:56 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| ((c >= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main()
// {
// 	char *str = "HElLLo";
// 	//char str1[] = "HELLO";

// 	printf("%d", ft_isalpha(str));
//     printf("%d", isalpha(str));    
// }
