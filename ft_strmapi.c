/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:58:01 by njeanbou          #+#    #+#             */
/*   Updated: 2023/10/26 19:00:36 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>
// char to_uppercase(unsigned int i, char c) {
//     return ft_toupper(c);
// }
// int main() {
//     const char *s = "Bonjourrrrrrrrrrrrrrrr";
//     char *resultat = ft_strmapi(s, to_uppercase);
//     if (resultat != NULL) {
//         printf("Résultat : '%s'\n", resultat);
//         free(resultat);
//     } else {
//         printf("Erreur lors de l'allocation mémoire.\n");
//     }
//     return 0;
// }