/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:18:21 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:18:24 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			str++;
		while (*str)
		{
			if (*str == ' ')
				break ;
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		while (*str)
		{
			if (*str != ' ')
				break ;
			str++;
		}
	}
	return (1);
}
