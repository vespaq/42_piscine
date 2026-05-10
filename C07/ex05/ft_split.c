/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muozdemi <muozdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:08:56 by muozdemi          #+#    #+#             */
/*   Updated: 2026/05/10 14:10:16 by muozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*word_dup(char *str, char *charset)
{
	int		len = 0;
	char	*word;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len] && !is_sep(str[len], charset))
	{
		word[len] = str[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i = 0;

	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!res)
		return (NULL);
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			res[i++] = word_dup(str, charset);
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	res[i] = NULL;
	return (res);
}