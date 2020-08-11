/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:40:56 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/02 17:40:58 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
#include "stdio.h"      //for printf()
#include "stdlib.h"     //for exit()

typedef struct		    t_list
{
    struct stack_list	*next;
    int                 data;
}					    s_list;

typedef struct			t_ps
{
	s_list 				*stack_a;
	s_list 				*stack_b;
}						s_ps;

s_list		*list_create_elem(int data);
void		list_push_back(s_ps *ps, int data, int num_stack);
void		list_push_front_a(s_ps *ps, int data);
void		list_push_front_b(s_ps *ps, int data);
int			list_check_duplicates_a(s_ps *ps, int num);
int 		list_s_size(s_list *lst);
int			recognition_func(s_ps *ps, char *com);
int 		push(s_ps *ps, int num_stack);
int 		reverse_rotate(s_ps *ps, char *com);
int 		list_delete(s_list **lst);

#endif
