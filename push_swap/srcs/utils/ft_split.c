/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:46:26 by jcummins          #+#    #+#             */
/*   Updated: 2024/04/13 15:46:28 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	wcount(char const *s, char c)
{
	int				i;
	unsigned int	words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

unsigned int	lcount(char const *s, char c, unsigned int i)
{
	unsigned int	letters;

	letters = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		letters++;
		i++;
	}
	return (letters);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int end)
{
	unsigned int	i;
	char			*out;

	i = 0;
	if (!s)
		return (NULL);
	out = malloc((end - start + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while ((start + i) < end)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	w;
	unsigned int	words;
	unsigned int	letters;

	i = 0;
	w = 0;
	words = wcount(s, c);
	if (!words)
		return (NULL);
	words++;
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (split == NULL || s == NULL)
		return (NULL);
	while (++w < words)
	{
		while (s[i] == c)
			i++;
		letters = lcount(s, c, i);
		split[w] = ft_substr(s, i, i + letters);
		i += (letters);
	}
	split[w] = NULL;
	return (split);
}
