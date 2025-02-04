/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:45:52 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/29 09:59:25 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

static	int	counter(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*temp_ptr;

	temp_ptr = (char *) s;
	while (n > 0)
	{
		*(temp_ptr++) = 0;
		n--;
	}
}

static char	*converting(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_bzero(temp, len + 1);
	return (temp);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = counter(nbr);
	result = converting(len);
	if (!result)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}

// int main(void)
// {
//     printf("ft_itoa(123) = %s\n", ft_itoa(123));           // "123"
//     printf("ft_itoa(-456) = %s\n", ft_itoa(-456));         // "-456"
//     printf("ft_itoa(0) = %s\n", ft_itoa(0));               // "0"
//     printf("ft_itoa(INT_MAX) = %s\n", ft_itoa(INT_MAX));   // "2147483647"
//     printf("ft_itoa(INT_MIN) = %s\n", ft_itoa(INT_MIN));   // "-2147483648"
//     printf("ft_itoa(7) = %s\n", ft_itoa(7));               // "7"
//     printf("ft_itoa(-3) = %s\n", ft_itoa(-3));             // "-3"
//     printf("ft_itoa(1000000) = %s\n", ft_itoa(1000000));   // "1000000"
//     printf("ft_itoa(-1000000) = %s\n", ft_itoa(-1000000)); // "-1000000"

//     return 0;
// }
