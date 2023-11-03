/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:08 by njeanbou          #+#    #+#             */
/*   Updated: 2023/11/01 14:33:06 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void	*), void	(*del)(void *))
// {
// 	t_list	*new;
// 	t_list	*node;

// 	if (!f || !del)
// 		return (NULL);
// 	new = NULL;
// 	while (lst)
// 	{
// 		node = ft_lstnew(f(lst->content));
// 		if (!node)
// 		{
// 			ft_lstclear(&new, (*del));
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new, node);
// 		lst = lst->next;
// 	}
// 	return (new);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*mapped;
// 	t_list	*tmp;

// 	if (lst == NULL || f == NULL || del == NULL)
// 		return (NULL);
// 	mapped = NULL;
// 	while (lst)
// 	{
// 		tmp = ft_lstnew((*f)(lst->content));
// 		if (tmp == NULL)
// 		{
// 			ft_lstclear(&tmp, (*del));
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&mapped, tmp);
// 		lst = lst->next;
// 	}
// 	return (mapped);
// }
