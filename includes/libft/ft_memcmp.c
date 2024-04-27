/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:53:02 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:36:11 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	i = 0;
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] < q[i])
			return (p[i] - q[i]);
		else if (p[i] > q[i])
			return (p[i] - q[i]);
		i++;
	}
	return (0);
}
