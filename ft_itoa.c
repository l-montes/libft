/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:43:43 by lmontes-          #+#    #+#             */
/*   Updated: 2022/11/17 14:15:11 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_neg(int n, int *sign)
{
	if (n < 0)
		*sign = -1;
	else
		*sign = 1;
	return (n *= *sign);
}

static size_t	nlen(int n)
{
	size_t	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static void	extract_int(char *num, int n, int *sign, size_t len)
{
	size_t	i;

	if (*sign == -1)
		i = 1;
	else
		i = 0;
	while (len > i)
	{
		num[len - 1] = '0' + (n % 10);
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*num;
	size_t	len;

	sign = 1;
	len = nlen (n);
	num = malloc(sizeof (char) * (len + 1));
	if (!num)
		return (NULL);
	if (n == -2147483648)
	{	
		ft_strlcpy(num, "-2147483648", 12);
		return (num);
	}
	n = check_neg(n, &sign);
	if (sign == -1)
		num[0] = '-';
	extract_int (num, n, &sign, len);
	num[len] = '\0';
	return (num);
}
