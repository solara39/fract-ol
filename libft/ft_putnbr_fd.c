/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:32:43 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 20:05:08 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_positive_fd(int n, int fd)
{
	long	d;
	char	tmp;

	d = 1;
	while (n / d != 0)
		d *= 10;
	d /= 10;
	while (d > 0)
	{
		tmp = n / d + '0';
		ft_putchar_fd(tmp, fd);
		n %= d;
		d /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_positive_fd(n, fd);
}
