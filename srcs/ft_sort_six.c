
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
