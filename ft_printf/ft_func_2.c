#include "ft_printf.h"

int	capac(long long int n)
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

int	capac_hex(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr((nb * (-1)));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putnbr_hex(unsigned long long nb)
{
	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) + 87);
	else if ((nb % 16) < 10)
		ft_putchar((nb % 16) + 48);
}

void	ft_putnbr_hex_XX(unsigned long long nb)
{
	if (nb >= 16)
		ft_putnbr_hex_XX(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) + 55);
	else if ((nb % 16) < 10)
		ft_putchar((nb % 16) + 48);
}
