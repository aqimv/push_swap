#include "push_swap.h"

int		sorted(t_data *frame)
{
	t_stack	*tmp;

	if (!frame->a || frame->b)
		return (0);
	tmp = frame->a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_data *frame, int len)
{
	if (!sorted(frame))
	{
		if (len < 6)
			sort_below_six(frame, len);
		else
			sort_insert(frame);
	}
}

int		main(int argc, char **argv)
{
	t_data	*frame;
	int		len;

	if (argc < 2)
		return (1);
	if (!check_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	frame = ft_data_create(argv);
	check_unic(frame);
	len = info_stack_len(frame->a);
	push_swap(frame, len);
	ft_data_free(frame);
	return (0);
}
