/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:48:51 by tyuan             #+#    #+#             */
/*   Updated: 2020/05/12 16:11:16 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*f_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void		f_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (alst && (*alst)->next)
		alst = &((*alst)->next);
	(*alst)->next = new;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newl;
	t_list *elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (lst)
	{
		if (!(newl = f_lstnew((*f)(lst->content))))
		{
			(*del)(lst->content);
			return (NULL);
		}
		lst = lst->next;
	}
	while (lst)
	{
		elem = f_lstnew((*f)(lst));
		lst = lst->next;
		f_lstadd_back(&newl, elem);
	}
	return (newl);
}
