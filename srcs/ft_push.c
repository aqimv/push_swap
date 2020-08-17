/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:18:33 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:18:38 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **rest, t_stack **dest)
{
	int	num;

	if (*rest)
	{
		num = (*rest)->num;
		ft_stack_del_top(&(*rest));
		ft_stack_add_top(&(*dest), ft_stack_create(num));
	}
}

void	pa(t_data *data, int mode)
{
	ft_push(&data->b, &data->a);
	if (mode == 0)
		write(1, "pa\n", 3);
}

void	pb(t_data *data, int mode)
{
	ft_push(&data->a, &data->b);
	if (mode == 0)
		write(1, "pb\n", 3);
}
