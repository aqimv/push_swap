
#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			str++;
		while (*str)
		{
			if (*str == ' ')
				break ;
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		while (*str)
		{
			if (*str != ' ')
				break ;
			str++;
		}
	}
	return (1);
}
