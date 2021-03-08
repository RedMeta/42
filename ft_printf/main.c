#include "ft_printf.h"

int main()
{
	ft_putnbr_base(ft_printf("TestiamoUnPo\n---%0d---\nScritto n."), "0123456789");
	return 0;
}