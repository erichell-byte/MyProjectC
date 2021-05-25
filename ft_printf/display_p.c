#include "ft_printf.h"

void	display_p (va_list arg, t_list *flags)
{
	int						i;
	unsigned long long int	hex;

	i = 0;
	hex = va_arg(arg, long long);
	if ((void *)hex == NULL && flags->for_s == 1)
		flags->length = null_hex(flags);
	else
	{	
		if (flags->precision != 0)
		{
			if (flags->precision < capac_hex(hex))
				flags->precision = capac_hex(hex);
			flags->length = p_prec_yes(flags, i, hex);
		}
		else if (flags->width == 0)
			flags->length = p_no_width(flags, hex);
		else if (flags->width != 0)
			flags->length = p_yes_width(flags, i, hex);
	}
}

int	p_prec_yes(t_list *flags, int i, unsigned long long int hex)
{
	if (flags->minus != 0)
	{
		ft_putstr("0x");
		while (i++ < flags->precision - capac_hex(hex))
			ft_putchar('0');
		flags->length = flags->length + i;
		ft_putnbr_hex(hex);
		i = 0;
		while (i++ < (flags->width - (flags->precision + 2)))
			ft_putchar(' ');
	}
	else if (flags->minus == 0)
	{
		while (i++ < (flags->width - (flags->precision + 2)))
			ft_putchar(' ');
		flags->length = flags->length + i;
		i = 0;
		ft_putstr("0x");
		while (i++ < flags->precision - capac_hex(hex))
			ft_putchar('0');
		ft_putnbr_hex(hex);
	}
	flags->length = flags->length + capac_hex(hex) + i;
	return (flags->length);
}

int	p_no_width(t_list *flags, unsigned long long int hex)
{
	ft_putstr("0x");
	ft_putnbr_hex(hex);
	if ((void *)hex == NULL)
		flags->length = flags->length;
	flags->length = flags->length + capac_hex(hex) + 2;
	return (flags->length);
}

int	p_yes_width(t_list *flags, int i, unsigned long long int hex)
{
	i = 0;
	if (flags->minus == 0)
	{
		while (i++ < (flags->width - (capac_hex(hex) + 2)))
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putnbr_hex(hex);
	}
	if (flags->minus != 0)
	{
		ft_putstr("0x");
		ft_putnbr_hex(hex);
		while (i++ < (flags->width - (capac_hex(hex) + 2)))
			ft_putchar(' ');
	}
	flags->length = flags->length + capac_hex(hex) + (i + 1);
	return (flags->length);
}

int	null_hex(t_list *flags)
{
	if (flags->width != 0)
	{
		while ((flags->width)-- > 2)
		{
			ft_putchar(' ');
			flags->length++;
		}
	}
	ft_putstr("0x");
	flags->length = flags->length + 2;
	return (flags->length);
}
