/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_lists2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 00:37:03 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/06 00:37:05 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		list_s_size(s_list *lst)
{
	int		k;
	s_list	*cur;

	cur = lst;
	k = 0;
	if (cur)
	{
		while (cur->next)
		{
			k++;
			cur = (s_list *) cur->next;
		}
	}
	else
		return (0);
	return (k + 1);
}

int 		list_delete(s_list **lst)
{
	s_list	*cur;
	s_list	*nxt;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur->next != NULL)
			nxt = (s_list *) cur->next;
		else
			nxt = NULL;
		free(cur);
		cur = NULL;
		cur = nxt;
	}
	return (0);
}
