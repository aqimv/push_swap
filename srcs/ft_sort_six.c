/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:21:57 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:21:59 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_pb(t_data *frame, int id)
{
	int i;

	i = info_stack_len(frame->a) - id + 1;
	while (i > 0)
	{
		ra(frame, 0);
		i--;
	}
	pb(frame, 0);
}

void	rra_pb(t_data *frame, int id)
{
	int	i;

	i = id - 1;
	while (i > 0)
	{
		rra(frame, 0);
		i--;
	}
	pb(frame, 0);
}
