/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:43:41 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:24:17 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

size_t	ft_find_index(char const *s, char c, size_t cnt)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			nb++;
		if (nb == cnt + 1)
			break ;
		while (s[i] != c)
			i++;
		i++;
	}
	return (i);
}

size_t	ft_substr_len(char const *s, char c, int cnt)
{
	size_t	start;
	size_t	i;

	start = ft_find_index(s, c, cnt);
	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - start);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	num[2];
	size_t	index[2];

	num[0] = ft_count_words(s, c);
	p = malloc(sizeof(char *) * (num[0] + 1));
	if (p == NULL)
		return (NULL);
	index[0] = 0;
	while (index[0] < num[0])
	{
		num[1] = ft_substr_len(s, c, index[0]);
		p[index[0]] = ft_substr(s, ft_find_index(s, c, index[0]), num[1]);
		if (p[index[0]] == NULL)
		{
			index[1] = -1;
			while (++index[1] < index[0])
				free(p[index[1]]);
			free(p);
			return (NULL);
		}
		index[0]++;
	}
	p[index[0]] = NULL;
	return (p);
}
