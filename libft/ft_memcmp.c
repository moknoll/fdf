/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:47:21 by mknoll            #+#    #+#             */
/*   Updated: 2024/10/15 12:53:34 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	*byte_s1;
	unsigned char	*byte_s2;

	i = 0;
	byte_s1 = (unsigned char *) s1;
	byte_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (byte_s1[i] != byte_s2[i])
		{
			return (byte_s1[i] - byte_s2[i]);
		}
		i++;
	}
	return (0);
}
