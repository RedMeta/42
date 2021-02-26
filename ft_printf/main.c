#include "ft_printf.h"

int main()
{
	int res;
	res = ft_printf("testiamo\n");
	ft_putnbr_base(res, "0123456789");
	return 0;
}