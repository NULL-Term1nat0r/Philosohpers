/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:58:04 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 18:36:18 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*b;

	n = NULL;
	while (lst)
	{
		b = ft_lstnew((*f)(lst->content));
		if (!b)
		{
			ft_lstclear(&n, del);
			return (NULL);
		}
		ft_lstadd_back(&n, b);
		lst = lst->next;
	}
	return (n);
}

// int main ()
// {
// 	t_list *list;
// 	list = NULL;
// 	list = ft_add_front(list, "Päckchen 1");
// 	list = ft_add_front(list, "Päckchen 2");
// 	list = ft_add_front(list, "Päckchen 3");

// 	print_list(list);

// 	return 0;
// }
