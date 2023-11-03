/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:57 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/30 18:11:16 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	d;
	size_t	s;

	src_len = ft_strlen(src);
	if (!dest && size == 0)
		return (src_len);
	d = ft_strlen(dest);
	dest_len = d;
	if (size <= dest_len)
		return (size + src_len);
	s = 0;
	while ((src[s]) && (d + 1 < size))
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	dest[d] = '\0';
	return (dest_len + src_len);
}
