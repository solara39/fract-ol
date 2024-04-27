/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:10 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 04:58:32 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

size_t	ft_find_end(char const *s1, char const *set)
{
	size_t	i;

	if (ft_strlen(s1) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index[3];
	size_t	i;
	char	*p;

	if (s1 == NULL || set == NULL)
		return (NULL);
	index[0] = ft_find_start(s1, set);
	index[1] = ft_find_end(s1, set);
	if (index[1] >= index[0])
		index[2] = index[1] - index[0] + 1;
	else
		index[2] = 0;
	i = 0;
	p = (char *)malloc(sizeof(char) * (index[2] + 1));
	if (p == NULL)
		return (NULL);
	while (index[0] <= index[1])
	{
		p[i] = s1[index[0]];
		i++;
		index[0]++;
	}
	p[i] = '\0';
	return (p);
}
