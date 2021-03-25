#include "ft_printf.h"

int main()
{
	char *test = "daniele mangolino";
	int a = ft_printf("Test mio ---%.0s---\n", test);
	int b = printf("Test suo ---%.0s---\n", test);
	printf("(%d // %d)", a, b);
	return 1;
}