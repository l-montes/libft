/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:14:25 by lmontes-          #+#    #+#             */
/*   Updated: 2022/10/19 10:03:26 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ltmp;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			ltmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ltmp;
		}
	}
}
