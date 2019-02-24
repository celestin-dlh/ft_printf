/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:11:12 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/14 10:03:04 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*prev;

	if (!lst)
		return (NULL);
	new = f(lst);
	prev = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		prev->next = tmp;
		prev = prev->next;
		lst = lst->next;
	}
	return (new);
}
