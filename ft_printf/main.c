#include "ft_printf.h"

int main()
{
	ft_putnbr_base(ft_printf("TestiamoUnPo\n---|%-13.975x|---\nScritto n.", -212, 21), "0123456789");
	ft_putchar('\n');
	return 0;
}