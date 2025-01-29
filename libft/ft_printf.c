/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:20 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/01/15 11:41:45 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_type(char type, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (type == 'd' || type == 'i')
		printed_chars += ft_putnbr(va_arg(args, int));
	else if (type == 's')
		printed_chars += ft_putstr(va_arg(args, char *));
	else if (type == 'c')
		printed_chars += ft_putchar(va_arg(args, int));
	else if (type == 'p')
		printed_chars += ft_putptr(va_arg(args, void *));
	else if (type == 'x')
		printed_chars += ft_puthex(va_arg(args, unsigned int));
	else if (type == 'X')
		printed_chars += ft_puthex_upper(va_arg(args, unsigned int));
	else if (type == 'u')
		printed_chars += ft_putunsigned(va_arg(args, unsigned int));
	else if (type == '%')
		printed_chars += write(1, "%", 1);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	va_start(args, format);
	i = 0;
	printed_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			printed_chars += ft_check_type(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
