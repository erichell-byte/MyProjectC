#include "ft_printf.h"

int	x_precon_minusoff_XX(long long int hex, t_list *flags, int i)
{
	ft_putnbr_hex_XX(hex);
	i = 0;
	while (i < (flags->width - capac_hex(hex)))
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}

int	x_minusoff_precoff_XX(long long int hex, t_list *flags, int i)
{
	if (flags->zero != 0)
	{
		while (i < (flags->width - capac_hex(hex)))
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_hex_XX(hex);
	}
	if (flags->zero == 0)
	{
		while (i < (flags->width - capac_hex(hex)))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr_hex_XX(hex);
	}
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}
