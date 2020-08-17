/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:17:54 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:17:58 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_odd(t_data *frame, t_arrint *arr, int chunk_id, int chunk_len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (k <= chunk_id / 2)
	{
		while ((i < chunk_len || j < chunk_len) && frame->a)
		{
			if (frame->a &&
				arr_cmp(arr, chunk_id / 2 + k, frame->a->num, chunk_len))
				to_up(frame, &i);
			else if (frame->a &&
				arr_cmp(arr, chunk_id / 2 - k, frame->a->num, chunk_len))
				to_down(frame, &j);
			else
				ra(frame, 0);
		}
		j = 0;
		i = 0;
		k++;
	}
}

void	odd_chunk(t_data *frame, t_arrint *arr, int chunk_id, int chunk_len)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = chunk_id / 2;
	while (i < chunk_len)
	{
		if (arr_cmp(arr, chunk, frame->a->num, chunk_len))
			to_up(frame, &i);
		else
			ra(frame, 0);
	}
	solution_odd(frame, arr, chunk_id, chunk_len);
}
