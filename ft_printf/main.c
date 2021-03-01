#include "ft_printf.h"

int main()
{
	ft_putnbr_base(ft_printf("TestiamoUnPo\n---%01.4x---\nScritto n.make re"), "0123456789");
	return 0;
}