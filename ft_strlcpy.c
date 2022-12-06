/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:33:12 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/13 15:39:09 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src [i];
		i++;
	}
	if (size < ft_strlen(src))
		dst[size - 1] = '\0';
	else
		dst[i] = '\0';
	return (ft_strlen(src));
}
