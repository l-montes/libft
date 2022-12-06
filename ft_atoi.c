/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:01:21 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/12 13:20:42 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (is_space(str[i]))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
	i++;
	}
	while (is_number(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (n > 9223372036854775807 && sign == 1)
		return (-1);
	else if (n > 9223372036854775807 && sign == -1)
		return (0);
	return (n * sign);
}
