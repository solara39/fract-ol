/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:28:38 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:05:32 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	j;
	size_t	max_cpy;

	if (dst == NULL)
		len_dst = 0;
	else
		len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	max_cpy = dstsize - len_dst - 1;
	j = 0;
	while (j < max_cpy)
	{
		if (src[j] == '\0')
			break ;
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[j + len_dst] = '\0';
	return (len_dst + len_src);
}
