#include "libft.h"

int	ft_atoi(const char *str)
{
	int			dig;
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	dig = 0;
	while (*str && (*str == '\f' || *str == '\t' || *str == ' ' || \
			*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
		if (*str == '-' && str++)
			sign = -1;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (num * sign) > 2147483647 || (num * sign) < -2147483648)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		str++;
	}
	return ((int)(num * sign));
}
