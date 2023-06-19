/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:16:03 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 18:58:35 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include "libft.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*ret;

// 	ret = malloc(sizeof(t_list));
// 	if (!ret)
// 		return (0);
// 	ret->content = content;
// 	ret->next = 0;
// 	return (ret);
// }

// Function name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the beginning of the list.

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = lst[0];
	lst[0] = new;
}
