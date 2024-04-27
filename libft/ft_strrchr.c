/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:47:08 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:00:02 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp;

	temp = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
