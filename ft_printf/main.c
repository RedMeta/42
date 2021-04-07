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
	int a = ft_printf("Test mio ###%12i###\n", 123);
	int b = printf("Test suo ###%12i###\n", 123);
	printf("(%d // %d)", a, b); 
	return 1;
}