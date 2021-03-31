#include "ft_printf.h"

int	main()
{
	int test = 1234;
	int a = ft_printf("Test mio ---%i---\n", test);
	int b = printf("Test suo ---%i---\n", test);
	printf("(%d // %d)", a, b); 
	return 1;
}