/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:09:47 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/19 12:40:50 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*rcontent;
	size_t	rsize;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		rcontent = ft_memalloc(content_size);
		rsize = content_size;
		ft_memcpy(rcontent, content, content_size);
		new->content = rcontent;
		new->content_size = rsize;
	}
	else
	{
		new->content_size = 0;
		new->content = NULL;
	}
	return (new);
}
