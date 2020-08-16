
#include "push_swap.h"

int		skipws(char *str)
{
	int count;

	count = 0;
	while (*str == ' ')
	{
		count++;
		str++;
	}
	while (ft_isdigit(*str) || *str == '+' || *str == '-')
	{
		count++;
		str++;
	}
	while (*str == ' ')
	{
		count++;
		str++;
	}
	return (count);
}

t_data	*ft_data_create(char **arg)
{
	t_data			*data;
	int				i;
	char			*str;
	long long int	num;

	if ((data = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	i = 1;
	while (arg[i])
	{
		str = arg[i];
		while (*str)
		{
			num = ft_newatoi(str, data);
			if (num > 2147483647 || num < -2147483648)
				ft_error(data);
			ft_stack_add_bot(&(data->a), ft_stack_create((int)num));
			str += skipws(str);
		}
		i++;
	}
	return (data);
}

void	ft_data_free(t_data *data)
{
	while (data->a)
		ft_stack_del_top(&data->a);
	while (data->b)
		ft_stack_del_top(&data->b);
	free(data);
}

