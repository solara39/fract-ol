/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:04:04 by skondo            #+#    #+#             */
/*   Updated: 2023/07/07 05:53:33 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_handle_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

int	ft_handle_overflow(const char *str, int index, int sign, long long result)
{
	if (result > LONG_MAX / 10 && sign != -1)
		return (-1);
	else if (result > LONG_MAX / 10 && sign == -1)
		return (0);
	else if (result == LONG_MAX / 10)
	{
		index++;
		if (str[index] > '6' && sign != -1)
			return (-1);
		else if (str[index] > '7' && sign == -1)
			return (0);
		return (1);
	}
	return (2);
}

int	ft_atoi(const char *str)
{
	int			index;
	long long	result;
	int			sign;
	int			overflow;

	index = 0;
	result = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	sign = ft_handle_sign(str, &index);
	if (ft_strncmp(str, "9223372036854775806", 19) == 0)
		return (-2);
	while (ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		overflow = ft_handle_overflow(str, index, sign, result);
		if (overflow != 2)
			return (overflow);
		index++;
	}
	return (result * sign);
}
