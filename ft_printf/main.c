#include "ft_printf.h"

int main()
{
	char *test = "abcdefghijk";
	int a = ft_printf("Test mio ---%20s---\n", test);
	int b = printf("Test suo ---%12.*s---\n", 11, test);
	printf("(%d // %d)", a, b);
	return 1;
}