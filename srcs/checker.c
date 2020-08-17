/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:17:38 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 18:17:40 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_data *frame, int mode)
{
	char	*line;

	mode = 1;
	while ((get_next_line(0, &line)) == 1)
	{
		go_ft(line, frame);
		free(line);
	}
}

void	sort_test(t_data *frame)
{
	t_stack		*tmp;
	int			error;

	tmp = frame->a;
	error = (frame->b) ? 1 : 0;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			error = 1;
		tmp = tmp->next;
	}
	if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int		main(int argc, char **argv)
{
	t_data	*frame;
	int		mode;

	frame = NULL;
	mode = 1;
	if (argc < 2)
		return (1);
	if (!check_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	frame = ft_data_create(argv);
	check_unic(frame);
	checker(frame, mode);
	sort_test(frame);
	ft_data_free(frame);
	return (0);
}
