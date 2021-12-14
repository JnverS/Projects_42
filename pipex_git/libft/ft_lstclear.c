/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:58:00 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/14 14:58:01 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
