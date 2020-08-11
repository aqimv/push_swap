/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:34:49 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/03 18:34:51 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list		*list_create_elem(int data)
{
    s_list	*a;

    a = (s_list *)malloc(sizeof(s_list));
    if (a)
    {
        a->data = data;
        a->next = NULL;
    }
    return (a);
}

void		list_push_back(s_ps *ps, int data, int num_stack)
{
    s_list	*a;
    s_list	*cur;

	cur = ps->stack_a;
    if (num_stack == 1)
    	cur = ps->stack_b;
    a = list_create_elem(data);
    if (cur)
    {
        while (cur->next)
            cur = (s_list *) cur->next;
        cur->next = (struct stack_list *) a;
    }
    else
	{
		ps->stack_a = a;
		if (num_stack == 1)
			ps->stack_b = a;
	}
}

void		list_push_front_a(s_ps *ps, int data)
{
    s_list	*a;
    s_list	*cur;

    a = list_create_elem(data);
    cur = ps->stack_a;
    if (cur)
    {
    	a->next = (struct stack_list *) ps->stack_a;
    	ps->stack_a = a;
    }
    else
    	ps->stack_a = a;
}

void 		list_push_front_b(s_ps *ps, int data)
{
	s_list	*a;
	s_list	*cur;

	a = list_create_elem(data);
	cur = ps->stack_b;
	if (cur)
	{
		a->next = (struct stack_list *) ps->stack_b;
		ps->stack_b = a;
	}
	else
		ps->stack_b = a;
}

int			list_check_duplicates_a(s_ps *ps, int num)
{
    s_list	*cur;

    cur = ps->stack_a;
    if (cur)
    {
        while (cur->next)
        {
            if (num == cur->data)
                return (1);
            cur = (s_list *) cur->next;
        }
    }
    return (0);
}
