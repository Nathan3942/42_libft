/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:00 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/01 12:43:05 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (0);
	if (needle[0] == '\0' || needle == haystack)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	j;
// 	size_t	i;

// 	if (!haystack || !needle)
// 		return (NULL);
// 	if (!needle || !needle[0])
// 		return ((char *)haystack);
// 	i = 0;
// 	while (haystack[i] && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] && needle[j] && i + j < len
// 			&& haystack[i + j] == needle[j])
// 			j++;
// 		if (!needle[j])
// 			return ((char *)(haystack + i));
// 		i++;
// 	}
// 	return (NULL);
// }
