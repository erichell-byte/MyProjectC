#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (1, &(s[i]), 1);
			i++;
		}
	}
	return ;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	capac_unsig(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
