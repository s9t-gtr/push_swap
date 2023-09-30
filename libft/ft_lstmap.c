/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:41:30 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:50:26 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*n;

	if (*f == NULL)
		return (NULL);
	t = NULL;
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&t, del);
			return (NULL);
		}
		ft_lstadd_back(&t, n);
		n = n->next;
		lst = lst->next;
	}
	return (t);
}
