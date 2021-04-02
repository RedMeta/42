#include "ft_printf.h"

int	main()
{
	char *s;
	int w, p;
	int i;
	i = 1234;
	w = 12;
	p = -1;
	s = NULL;
	int a = ft_printf("Test mio ---%.6i---\n", -3);
	int b = printf("Test suo ---%.6i---\n", -3);
	printf("(%d // %d)", a, b); 
	return 1;
}