/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:03:37 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/23 18:00:34 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*char_ptr;
	size_t			i;

	i = 0;
	char_ptr = (unsigned char *)ptr;
	while (i < len)
	{
		char_ptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
