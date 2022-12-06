/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:48:03 by lmontes-          #+#    #+#             */
/*   Updated: 2022/11/17 13:58:33 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sbstr;
	unsigned int	i;
	size_t			l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start > l)
	{
		sbstr = ft_strdup("");
		return (sbstr);
	}
	if (len > l)
		len = l - start;
	sbstr = malloc(sizeof(char) * (len + 1));
	if (!sbstr)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}
