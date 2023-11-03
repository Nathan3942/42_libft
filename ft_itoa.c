/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:12:44 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/30 18:42:45 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	sizetab(long nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i = 1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

char	*itoa(long nb, char *str, size_t i)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb > 9)
	{
		itoa(nb / 10, str, i - 1);
		itoa(nb % 10, str, i);
	}
	else
	{
		str[i] = nb + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;
	size_t	end;

	i = sizetab(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	end = i;
	if (str == NULL)
		return (NULL);
	itoa(n, str, end - 1);
	str[end] = '\0';
	return (str);
}
