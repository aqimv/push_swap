/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:20:28 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:20:31 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

void	finish(t_data *frame, int *arr)
{
	if (frame->a->num > frame->a->next->num)
		sa(frame, 0);
	if (get_last(frame->a) < arr[3])
		rra(frame, 0);
	if (get_last(frame->a) < arr[3])
		rra(frame, 0);
	if (frame->a->num > frame->a->next->num)
		sa(frame, 0);
}

void	push_a(t_data *frame, int *arr)
{
	if ((info_stack_len(frame->a) > 1) &&
		(frame->a->num == arr[0] || frame->a->num == arr[1]))
		ra(frame, 0);
	pa(frame, 0);
}

void	rb_pa(t_data *frame, int *arr)
{
	while (frame->b->num != arr[3])
	{
		if (frame->b->num == arr[0] ||
			frame->b->num == arr[1] || frame->b->num == arr[2])
			push_a(frame, arr);
		else
			rb(frame, 0);
	}
	push_a(frame, arr);
	if (info_stack_len(frame->a) == 2 && frame->a->num > frame->a->next->num)
		sa(frame, 0);
	if (info_stack_len(frame->a) == 3)
		sort3(frame);
	if (info_stack_len(frame->a) >= 4)
		finish(frame, arr);
}

void	rrb_pa(t_data *frame, int *arr)
{
	while (frame->b->num != arr[3])
	{
		if (frame->b->num == arr[0] ||
			frame->b->num == arr[1] || frame->b->num == arr[2])
			push_a(frame, arr);
		else
			rrb(frame, 0);
	}
	push_a(frame, arr);
	if (info_stack_len(frame->a) == 2 && frame->a->num > frame->a->next->num)
		sa(frame, 0);
	if (info_stack_len(frame->a) == 3)
		sort3(frame);
	if (info_stack_len(frame->a) >= 4)
		finish(frame, arr);
}
