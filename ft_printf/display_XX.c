#include "ft_printf.h"

void	display_XX (va_list arg, t_list *flags)
{
	int					i;
	long long int		hex;

	i = 0;
	hex = va_arg(arg, unsigned int);
	if (flags->for_s == 1 && hex == 0)
		flags->length = x_hex_hull_XX(flags);
	else if (flags->is_precision > 0)
	{
		if (flags->width == 0)
			flags->length = x_precision_XX(hex, flags, i);
		if (flags->width != 0 && flags->minus == 0)
			flags->length = x_widthon_minusoff_XX(hex, flags, i);
		if (flags->width != 0 && flags->minus != 0)
			flags->length = x_widthon_minus_on_XX(hex, flags, i);
	}
	else if (flags->is_precision < 0)
	{
		if (flags->minus != 0)
			flags->length = x_precon_minusoff_XX(hex, flags, i);
		if (flags->minus == 0)
			flags->length = x_minusoff_precoff_XX(hex, flags, i);
	}
}

int	x_hex_hull_XX(t_list *flags)
{
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		flags->length++;
	}
	return (flags->length);
}

int	x_precision_XX(long long int hex, t_list *flags, int i)
{
	while (i < (flags->precision - (capac_hex(hex))))
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr_hex_XX(hex);
	flags->length = flags->length + capac_hex(hex) + i;
	return (flags->length);
}

int	x_widthon_minusoff_XX(long long int hex, t_list *flags, int i)
{
	i = 0;
	if (flags->precision < (capac_hex(hex)))
		flags->precision = capac_hex(hex);
	while (i < flags->width - flags->precision)
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i;
	i = 0;
	while (i < (flags->precision - (capac_hex(hex))))
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr_hex_XX(hex);
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}

int	x_widthon_minus_on_XX(long long int hex, t_list *flags, int i)
{
	if (flags->precision < (capac_hex(hex)))
		flags->precision = capac_hex(hex);
	while (i < (flags->precision - (capac_hex(hex))))
	{
		ft_putchar('0');
		i++;
	}
	flags->length = flags->length + i;
	i = 0;
	ft_putnbr_hex_XX(hex);
	while (i < flags->width - flags->precision)
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i + capac_hex(hex);
	return (flags->length);
}
