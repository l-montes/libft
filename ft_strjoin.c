/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:03:55 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/12 20:56:12 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*join;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (l1 + l2 +1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		join[i] = s1[i];
		i++;
	}	
	i = 0;
	while (i < l2)
		join[l1++] = s2[i++];
	join[l1++] = '\0';
	return (join);
}
