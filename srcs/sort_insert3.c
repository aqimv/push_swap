
#include "push_swap.h"

int		get_id(t_stack *stack, int num)
{
	int	count;

	count = 1;
	while (stack)
	{
		if (stack->num == num)
			return (count);
		count++;
		stack = stack->next;
	}
	return (0);
}

int		*sort_arr(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			j--;
		}
		i++;
	}
	return (arr);
}

int		*create_arr(t_stack *stack, int *len)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	*len = info_stack_len(stack);
	arr = malloc(sizeof(int) * *len + 1);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->num;
		i++;
		tmp = tmp->next;
	}
	return (sort_arr(arr, *len));
}

int		arr_cmp(t_arrint *arr, int chunk, int num, int chunk_len)
{
	int	i;

	i = chunk_len * chunk;
	while (i < arr->len && i < chunk_len * (chunk + 1))
	{
		if (arr->m[i] == num)
			return (1);
		i++;
	}
	return (0);
}
