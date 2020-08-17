/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:19:13 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:19:17 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_stack_create(int num)
{
	t_stack *elem;

	elem = malloc(sizeof(t_stack));
	elem->num = num;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void		ft_stack_add_top(t_stack **s, t_stack *elem)
{
	t_stack	*tmp;

	if (*s)
	{
		tmp = *s;
		tmp->prev = elem;
		elem->next = tmp;
		elem->prev = NULL;
	}
	*s = elem;
}

void		ft_stack_add_bot(t_stack **s, t_stack *elem)
{
	t_stack	*tmp;

	if (*s)
	{
		tmp = *s;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
		elem->next = NULL;
	}
	else
		*s = elem;
}

void		ft_stack_del_top(t_stack **s)
{
	t_stack	*tmp;

	if (*s)
	{
		tmp = *s;
		if (tmp->next)
			tmp->next->prev = NULL;
		*s = tmp->next;
		free(tmp);
	}
}

void		ft_stack_del_bot(t_stack **s)
{
	t_stack	*tmp;

	if (*s)
	{
		tmp = *s;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		free(tmp);
	}
}
