/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:17:37 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/30 18:02:49 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char		*char_dest;
	const char	*char_src;

	char_dest = (char *)dest;
	char_src = (const char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*char_dest = *char_src;
		char_dest++;
		char_src++;
		n--;
	}
	return (dest);
}
