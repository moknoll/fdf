/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:17:25 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/01/15 11:42:04 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(uintptr_t num)
{
	int		count;
	char	hex_digit;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count += ft_puthex(num / 16);
	hex_digit = "0123456789abcdef"[num % 16];
	count += ft_putchar(hex_digit);
	return (count);
}

int	ft_puthex_upper(uintptr_t num)
{
	char	hex_digit;
	int		count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count += ft_puthex_upper(num / 16);
	hex_digit = "0123456789ABCDEF"[num % 16];
	count += ft_putchar(hex_digit);
	return (count);
}
