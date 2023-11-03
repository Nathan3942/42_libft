/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:58 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/01 13:16:36 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(dest + i - 1) = *(s + start + i - 1);
		*(dest + i - 1) = '\0';
	}
	return (dest);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

//
//
//
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*src;
// 	int		i;

// 	i = 0;
// 	src = (char *)malloc ((len + 1) * sizeof(char));
// 	if (src == NULL)
// 		return (NULL);
// 	while ((i < len) && (s[i + start] != '\0'))
// 	{
// 		src[i] = s[i + start];
// 		i++;
// 	}
// 	src[i] = '\0';
// 	return (src);
// }
