/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:57:47 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:24 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*char_ptr;

	char_ptr = (char *)ptr;
	while (n > 0)
	{
		*char_ptr = 0;
		char_ptr++;
		n--;
	}
}
