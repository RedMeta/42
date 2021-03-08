#include "../ft_printf.h"

int	ft_atoi(const char *str)
{
	int	nbr;

	nbr = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str && (*str >= '0' || *str <= '9'))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr);
}