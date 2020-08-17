/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:21:21 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:21:25 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	info_min(t_stack *stack)
{
	long int	min;

	min = stack->num;
	while (stack)
	{
		min = (min > stack->num) ? stack->num : min;
		stack = stack->next;
	}
	return (min);
}

int	info_stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	info_max(t_stack *stack)
{
	long int	max;

	max = stack->num;
	while (stack)
	{
		max = (max < stack->num) ? stack->num : max;
		stack = stack->next;
	}
	return (max);
}
