/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:45:39 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/04 21:45:42 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list		*swap_elem(s_list *lst)
{
	s_list	*first;
	s_list	*second;
	s_list	*third;

	if (list_s_size(lst) > 1)
	{
		first = lst;
		third = lst;
		second = (s_list *) third->next;
		third = (s_list *) second->next;
		first->next = (struct stack_list *) third;
		second->next = (struct stack_list *) first;
		lst = second;
	}
	return(lst);
}

int 		swap(s_ps *ps, char *com)
{
	if (!(ft_strcmp("sa", com)))
		ps->stack_a = swap_elem(ps->stack_a);
	else if (!(ft_strcmp("sb", com)))
		ps->stack_b = swap_elem(ps->stack_b);
	else if (!(ft_strcmp("ss", com)))
	{
		ps->stack_a = swap_elem(ps->stack_a);
		ps->stack_b = swap_elem(ps->stack_b);
	}
	return (0);
}

s_list		*rotate_stack(s_list *lst)
{
	s_list	*first;
	s_list	*second;
	s_list 	*cur;

	if (list_s_size(lst) > 1)
	{
		first = lst;
		second = (s_list *) lst->next;
		cur = lst;
		while (cur->next)
			cur = (s_list *) cur->next;
		cur->next = (struct stack_list *) first;
		cur = (s_list *) cur->next;
		cur->next = NULL;
		lst = second;
	}
	return (lst);
}

int 		rotate(s_ps *ps, char *com)
{
	if (!(ft_strcmp("ra", com)))
		ps->stack_a = rotate_stack(ps->stack_a);
	else if (!(ft_strcmp("rb", com)))
		ps->stack_b = rotate_stack(ps->stack_b);
	else if (!(ft_strcmp("rr", com)))
	{
		ps->stack_a = rotate_stack(ps->stack_a);
		ps->stack_b = rotate_stack(ps->stack_b);
	}
	return(0);
}

int			recognition_func(s_ps *ps, char *com)
{
	if (!(ft_strcmp("sa", com)) || !(ft_strcmp("sb", com)) || !(ft_strcmp("ss", com)))
		return(swap(ps, com));
	else if (ft_strcmp("pa", com) == 0)
		return(push(ps, 0));
	else if (ft_strcmp("pb", com) == 0)
		return(push(ps, 1));
	else if (!(ft_strcmp("ra", com)) || !(ft_strcmp("rb", com)) || !(ft_strcmp("rr", com)))
		return(rotate(ps, com));
	else if (!(ft_strcmp("rra", com)) || !(ft_strcmp("rrb", com)) || !(ft_strcmp("rrr", com)))
		return(reverse_rotate(ps, com));
	else
		return (1);
}
