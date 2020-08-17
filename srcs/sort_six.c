/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:20:42 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:20:45 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_data *frame)
{
	int	a;
	int	b;

	a = frame->a->num;
	b = frame->a->next->num;
	if (a > b)
		sa(frame, 0);
}

void	sort3(t_data *frame)
{
	long int		a;
	long int		b;
	long int		c;

	a = frame->a->num;
	b = frame->a->next->num;
	c = frame->a->next->next->num;
	if (a < b && a < c && b > c)
	{
		rra(frame, 0);
		sa(frame, 0);
	}
	else if (a > b && a < c && b < c)
		sa(frame, 0);
	else if (a < b && a > c && b > c)
		rra(frame, 0);
	else if (a > b && a > c && b < c)
		ra(frame, 0);
	else if (a > b && a > c && b > c)
	{
		ra(frame, 0);
		sa(frame, 0);
	}
}

void	sort4(t_data *frame)
{
	long int	min;
	int			id;

	min = info_min(frame->a);
	id = get_id(frame->a, min);
	id--;
	if (id > info_stack_len(frame->a) / 2 + info_stack_len(frame->a) % 2)
	{
		id = info_stack_len(frame->a) - id;
		while (id-- > 0)
			rra(frame, 0);
		pb(frame, 0);
	}
	else
	{
		while (id-- > 0)
			ra(frame, 0);
		pb(frame, 0);
	}
	sort3(frame);
	pa(frame, 0);
}

void	sort5(t_data *frame)
{
	long int	min;
	int			id;

	min = info_min(frame->a);
	id = get_id(frame->a, min);
	id--;
	if (id > info_stack_len(frame->a) / 2 + info_stack_len(frame->a) % 2)
	{
		id = info_stack_len(frame->a) - id;
		while (id-- > 0)
			rra(frame, 0);
		pb(frame, 0);
	}
	else
	{
		while (id-- > 0)
			ra(frame, 0);
		pb(frame, 0);
	}
	sort4(frame);
	pa(frame, 0);
}

void	sort_below_six(t_data *frame, int len)
{
	if (!frame->a)
		ft_error(frame);
	if (len == 2)
		sort2(frame);
	if (len == 3)
		sort3(frame);
	if (len == 4)
		sort4(frame);
	if (len == 5)
		sort5(frame);
}
