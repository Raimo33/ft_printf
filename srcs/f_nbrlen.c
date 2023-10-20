
#include "../ft_printf.h"

unsigned int	f_nbrlen(long long n, unsigned int base)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}
