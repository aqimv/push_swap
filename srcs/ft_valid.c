
#include "push_swap.h"

void	check_unic(t_data *frame)
{
	t_stack *tmp;
	t_stack *stack;

	stack = frame->a;
	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num == tmp->num)
				ft_error(frame);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

int		check_valid(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
