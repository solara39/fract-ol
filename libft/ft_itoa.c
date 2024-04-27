/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:21:59 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:38:19 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10 != 0 || n % 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	ft_insert_digit(long n, size_t index, size_t len)
{
	size_t	i;
	long	d;
	char	remain;

	d = 1;
	i = 0;
	if (n < 0)
	{
		if (index == 0)
			return ('-');
		n *= -1;
		index--;
		len--;
	}
	while (i++ < len)
		d *= 10;
	d /= 10;
	i = 0;
	while (i++ <= index)
	{
		remain = n / d + 48;
		n %= d;
		d /= 10;
	}
	return (remain);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*p;
	size_t	i;

	i = 0;
	len = ft_count_len(n);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = ft_insert_digit(n, i, len);
		i++;
	}
	p[i] = '\0';
	return (p);
}
