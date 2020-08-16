
#include "push_swap.h"

int		ft_chunk_len(int len)
{
	double	dbl;
	int		i;
	int		d;

	dbl = ft_sqrt(len);
	i = dbl - (int)dbl == 0 ? 0 : 1;
	d = (int)dbl + i;
	return (d * 2);
}

void	get_max_arr(t_data *frame, t_arrint *arr, int *max_arr)
{
	int i;

	i = 0;
	max_arr[3] = info_max(frame->b);
	while (arr->m[i] != max_arr[3])
		i++;
	max_arr[2] = arr->m[i - 1];
	max_arr[1] = arr->m[i - 2];
	max_arr[0] = arr->m[i - 3];
}

void	to_a(t_data *frame, t_arrint *arr)
{
	int i;
	int max;
	int max_arr[4];

	get_max_arr(frame, arr, max_arr);
	max = info_max(frame->b);
	i = get_id(frame->b, max);
	if (i > info_stack_len(frame->b) / 2)
		rrb_pa(frame, max_arr);
	else
		rb_pa(frame, max_arr);
}

int		ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

void	sort_insert(t_data *frame)
{
	t_arrint	arr;
	int			chunk_len;
	int			chunk_id;
	int			i;

	arr.m = create_arr(frame->a, &arr.len);
	chunk_len = ft_chunk_len(arr.len + 1);
	chunk_id = ft_sqrt(arr.len + 1) / 2;
	i = 0;
	if (chunk_id % 2)
		odd_chunk(frame, &arr, chunk_id, chunk_len);
	else
		even_chunk(frame, &arr, chunk_id, chunk_len);
	while (info_stack_len(frame->b))
		to_a(frame, &arr);
}
