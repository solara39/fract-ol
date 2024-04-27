/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:44:24 by skondo            #+#    #+#             */
/*   Updated: 2023/07/05 15:40:59 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/*int main()
{
	printf("%d\n",ft_isdigit('0'));
	printf("%d\n",ft_isdigit('9'));
	printf("%d\n",ft_isdigit('a'));
	printf("%d\n",ft_isdigit('A'));
	printf("%d\n",ft_isdigit(';'));
}*/
