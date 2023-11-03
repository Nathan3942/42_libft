/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:45:20 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/01 14:33:57 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **dest, int i)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **dest, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		dest[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!dest[word])
			return (free_array(dest, word));
		ft_putword(dest[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	dest[word] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char			**dest;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!dest)
		return (0);
	dest = ft_split_words(s, c, dest, num_words);
	return (dest);
}

// size_t	count_word(const char *s, char c)
// {
// 	size_t	i;
// 	size_t	nbword;

// 	nbword = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 			nbword++;
// 		i++;
// 	}
// 	nbword += 1;
// 	return (nbword);
// }

// char	*strword(const char *start, const char *end)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*str;

// 	len = end - start;
// 	i = 0;
// 	str = (char *)malloc((len + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		str[i] = start[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// void	free_dest(char **dest, int i)
// {
// 	int	j;

// 	j = 0;
// 	while (j < i)
// 	{
// 		free(dest[j]);
// 		j++;
// 	}
// 	free(dest);
// }

// char	**splitword(const char *s, char c, char **dest)
// {
// 	size_t		i;
// 	const char	*start;

// 	i = 0;
// 	while (*s != '\0')
// 	{
// 		if (*s != c)
// 		{
// 			start = s;
// 			while (*s != '\0' && *s != c)
// 				s++;
// 			dest[i] = strword(start, s);
// 			if (dest[i] == NULL)
// 			{
// 				free_dest(dest, i);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 		else
// 			s++;
// 	}
// 	dest[i] = NULL;
// 	return (dest);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char		**dest;
// 	size_t		i;
// 	size_t		nbword;

// 	nbword = 0;
// 	i = 0;
// 	nbword = count_word(s, c);
// 	dest = (char **)malloc((nbword + 1) * sizeof(char *));
// 	if (dest == NULL)
// 		return (NULL);
// 	dest = splitword(s, c, dest);
// 	return (dest);
// }
