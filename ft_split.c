/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:46:00 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/02 12:31:30 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_reps(char const *s, char c)
{
	int	n;
	int	flag;

	n = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		else if (*s != c && flag == 0)
		{
			flag = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static void	free_matrix(char **matrix, int row)
{
	while (row >= 0)
	{
		free(matrix[row]);
		row--;
	}
	free(matrix);
}

static const char	*str_line(char **split, const char *s, char c, int row)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	split[row] = malloc(sizeof(char) * (len + 1));
	if (split[row] == 0)
	{
		free_matrix(split, row);
		return (NULL);
	}
	s = s + (i - len);
	ft_strlcpy(split[row], s, len + 1);
	return (s + len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	n = c_reps (s, c);
	i = 0;
	split = malloc (sizeof(char *) * (n + 1));
	if (!split)
		return (NULL);
	while (i < n)
	{
		s = str_line (split, s, c, i);
		if (!s)
			return (NULL);
		i++;
	}
	split[n] = 0;
	return (split);
}
