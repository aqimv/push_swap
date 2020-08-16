
#include "push_swap.h"

void	sort2(t_data *frame)
{
	int	a;
	int	b;

	a = frame->a->num;
	b = frame->a->next->num;
	if (a > b)
		sa(frame, 0);
}

void	sort3(t_data *frame)
{
	long int		a;
	long int		b;
	long int		c;

	a = frame->a->num;
	b = frame->a->next->num;
	c = frame->a->next->next->num;
	if (a < b && a < c && b > c)
	{
		rra(frame, 0);
		sa(frame, 0);
	}
	else if (a > b && a < c && b < c)
		sa(frame, 0);
	else if (a < b && a > c && b > c)
		rra(frame, 0);
	else if (a > b && a > c && b < c)
		ra(frame, 0);
	else if (a > b && a > c && b > c)
	{
		ra(frame, 0);
		sa(frame, 0);
	}
}

void	sort4(t_data *frame)
{
	long int	min;
	int			id;

	min = info_min(frame->a);
	id = get_id(frame->a, min);
	if (id > info_stack_len(frame->a) / 2 + info_stack_len(frame->a) % 2)
		ra_pb(frame, id);
	else
		rra_pb(frame, id);
	sort3(frame);
	pa(frame, 0);
}

void	sort5(t_data *frame)
{
	long int	min;
	int			id;

	min = info_min(frame->a);
	id = get_id(frame->a, min);
	if (id > info_stack_len(frame->a) / 2 + info_stack_len(frame->a) % 2)
		ra_pb(frame, id);
	else
		rra_pb(frame, id);
	sort4(frame);
	pa(frame, 0);
}

void	sort_below_six(t_data *frame, int len)
{
	if (!frame->a)
		ft_error(frame);
	if (len == 2)
		sort2(frame);
	if (len == 3)
		sort3(frame);
	if (len == 4)
		sort4(frame);
	if (len == 5)
		sort5(frame);
}
