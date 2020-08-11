/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspaghet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:26:17 by cspaghet          #+#    #+#             */
/*   Updated: 2020/08/02 17:26:20 by cspaghet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				print_list(s_list *lst)
{
    s_list			*cur;

    cur = lst;
    if (cur)
    {
        while (cur->next)
        {
            ft_putnbr(cur->data);
            ft_putstr(" ");
            cur = (s_list *) cur->next;
        }
        ft_putnbr(cur->data);
    }
    ft_putchar('\n');
}

int 				sorted(s_list *lst)
{
	s_list			*cur;
	s_list 			*local;

	cur = lst;
	if (cur)
	{
		local = (s_list *) cur->next;
		while ((cur->next) && (cur->data < local->data))
		{
			cur = (s_list *) cur->next;
			local = (s_list *) cur->next;
		}
	}
	return (cur->next == NULL ? 0 : 1);
}

int				input_validation(char *input)
{
    int				i;
    long long int	a;

    i = 0;
    while (((input[i] >= 9) && (input[i] <= 13)) || (input[i] == 32) || (input[i] == 43) || (input[i] == 45))
        i++;
    while (i < (int)ft_strlen(input))
    {
        if (!(ft_isdigit(input[i])))
            return (1);
        i++;
    }
    if ((ft_strcmp(input, "-") == 0) || (ft_strcmp(input, "+") == 0))
        return (1);
    a = ft_atoi(input);
    if ((a > 2147483647) || (a < -2147483648))
        return (1);
    return (0);
}

int				checker(int argc, char **argv, s_ps *ps)
{
    int				i;

    i = 1;
    while (i < argc)
    {
        if (input_validation(argv[i]) || (list_check_duplicates_a(ps, ft_atoi(argv[i]))))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        list_push_back(ps, ft_atoi(argv[i]), 0);
        i++;
    }
    return (0);
}

int 				main(int argc, char **argv)
{
	s_ps			ps;
	char			*buf;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	checker(argc, argv, &ps);
	if (!(ps.stack_a))
		return (0);
	while ((get_next_line(0, &buf)) > 0)
	{
		if (recognition_func(&ps, buf))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(buf);
	}
	free(buf);
	if (!(sorted(ps.stack_a)) && (list_s_size(ps.stack_b) == 0))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	list_delete(&ps.stack_a);
	list_delete(&ps.stack_b);
	return (0);
}
