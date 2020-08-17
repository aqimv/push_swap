/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:21:33 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:21:36 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				first_ind(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\v' ||
		s[i] == '\t' || s[i] == '\r' || s[i] == '\f')
		i++;
	return (i);
}

long long int	ft_newatoi(const char *str, t_data *frame)
{
	int				i;
	long long int	rez;
	long long int	new_rez;
	int				sign;

	sign = 1;
	rez = 0;
	if (ft_strlen(str) > 12)
		ft_error(frame);
	i = first_ind((char *)str);
	if (str[i] == '+' || str[i] == '-')
	{
		sign *= str[i] == '-' ? -1 : 1;
		i++;
		if (!ft_isdigit(str[i]))
			ft_error(frame);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		new_rez = rez * 10 + str[i++] - '0';
		if (rez > new_rez)
			return (sign == -1 ? 0 : -1);
		rez = new_rez;
	}
	return (rez * sign);
}
