/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:23:39 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/02 12:36:21 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;

	if (!dst && !src)
		return (dst);
	d = dst;
	while (n > 0)
	{
		*d = *(char *)src;
		d++;
		src++;
		n--;
	}
	return (dst);
}
