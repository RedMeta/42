#include "ft_printf.h"

int main()
{
/*	ft_putnbr_base(ft_printf("TestiamoUnPo\n---|%21c|---\nScritto n.", 'X'), "0123456789");
	ft_putchar('\n');  */
	int a = ft_printf("Test mio ---%-05%---\n");
	int b = printf("Test mio ---%-05%---\n");
	printf("(%d // %d)", a, b);
	return 0;
}