#include "ft_printf.h"

int	x_precon_minusoff(long long int hex, t_list *flags, int i)
{
	ft_putnbr_hex(hex);
	i = 0;
	while (i < (flags->width - capac_hex(hex)))
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}

int	x_minusoff_precoff(long long int hex, t_list *flags, int i)
{
	if (flags->zero != 0)
	{
		while (i < (flags->width - capac_hex(hex)))
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_hex(hex);
	}
	if (flags->zero == 0)
	{
		while (i < (flags->width - capac_hex(hex)))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr_hex(hex);
	}
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}
