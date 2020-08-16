
#include "push_swap.h"

void	ft_error(t_data *frame)
{
	write(2, "Error\n", 6);
	ft_data_free(frame);
	exit(-1);
}
