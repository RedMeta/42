#include "ft_printf.h"

int main()
{
	ft_putnbr_base(ft_printf("TestiamoUnPo\n---|%*x|---\nScritto n.", 42), "0123456789");
	ft_putchar('\n');
	return 0;
}