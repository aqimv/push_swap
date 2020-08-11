/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 01:14:19 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/06 01:14:21 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		push(s_ps *ps, int num_stack)
{
	s_list	*sec;

	if (num_stack == 1)
	{
		if (list_s_size(ps->stack_a) > 0)
		{
			sec = (s_list *) ps->stack_a->next;
			ps->stack_a->next = (struct stack_list *) ps->stack_b;
			ps->stack_b = ps->stack_a;
			ps->stack_a = sec;
		}
	}
	else
	{
		if (list_s_size(ps->stack_b) > 0)
		{
			sec = (s_list *) ps->stack_b->next;
			ps->stack_b->next = (struct stack_list *) ps->stack_a;
			ps->stack_a = ps->stack_b;
			ps->stack_b = sec;
		}
	}
	return (0);
}

s_list		*reverse_rotate_stack(s_list *lst)
{
	s_list	*first;
	s_list 	*cur;
	s_list 	*cur2;

	if (list_s_size(lst) > 1)
	{
		first = lst;
		cur = lst;
		cur2 = lst;
		while (cur->next)
			cur = (s_list *) cur->next;
		cur->next = (struct stack_list *) first;
		while ((s_list *) cur2->next != cur)
			cur2 = (s_list *) cur2->next;
		cur2->next = NULL;
		lst = cur;
	}
	return (lst);
}

int 		reverse_rotate(s_ps *ps, char *com)
{
	if (!(ft_strcmp("rra", com)))
		ps->stack_a = reverse_rotate_stack(ps->stack_a);
	else if (!(ft_strcmp("rrb", com)))
		ps->stack_b = reverse_rotate_stack(ps->stack_b);
	else if (!(ft_strcmp("rrr", com)))
	{
		ps->stack_a = reverse_rotate_stack(ps->stack_a);
		ps->stack_b = reverse_rotate_stack(ps->stack_b);
	}
	return(0);
}
