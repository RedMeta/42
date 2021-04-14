#include "ft_printf.h"

int	main()
{
	char *s;
	int w, p;
	unsigned i;

	i = 4294967295;
	w = -12;
	p = -1;
	s = NULL;
	int a = ft_printf("Test mio ###%i###\n",i);
	int b = printf("Test suo ###%i###\n", i);
	printf("(%d // %d)", a, b); 
	return 1;
}