/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:31:05 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/22 10:18:10 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	c;

	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
	write(fd, "\n", 1);
}

// int main()
// {
// 	char *str = "Hello";

// 	ft_putendl_fd(str, 1);
// }
