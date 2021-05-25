#include "ft_printf.h"

void	display_d (va_list arg, t_list *flags, char **start_line)
{
	long long		d;
	int				i;
	long long		j;

	i = 0;
	if (**start_line == 'u')
		d = va_arg(arg, unsigned int);
	else
		d = va_arg(arg, int);
	j = d;
	if (flags->for_s == 1 && d == 0)
		flags->length = d_null(flags);
	else if (flags->is_precision > 0)
	{
		if (flags->width == 0)
			flags->length = d_no_width_yes_prec(flags, d);
		if (flags->width != 0 && flags->minus == 0)
			flags->length = d_yes_width_yes_prec_nominus(flags, d);
		if (flags->width != 0 && flags->minus != 0)
			flags->length = d_yes_width_yes_prec_yesminus(flags, d, i, j);
	}
	else if (flags->is_precision < 0)
		flags->length = d_precision_no(flags, d, i);
}

int	d_no_width_yes_prec(t_list *flags, long long d)
{
	int	i;

	i = 0;
	if (d < 0)
	{
		d = d * -1;
		ft_putchar('-');
		flags->length++;
	}
	while (i < (flags->precision - (capac(d))))
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr(d);
	flags->length = flags->length + i + capac(d);
	return (flags->length);
}

int	d_yes_width_yes_prec_nominus(t_list *flags, long long d)
{
	int	i;

	i = 0;
	if (d < 0)
		i++;
	if (flags->precision < capac(d))
		flags->precision = capac(d);
	while (i < ((flags->width) - flags->precision))
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i;
	if (d < 0)
	{
		d = d * -1;
		ft_putchar('-');
	}
	i = 0;
	while (i++ < (flags->precision - (capac(d))))
		ft_putchar('0');
	ft_putnbr(d);
	flags->length = flags->length + (i - 1) + capac(d);
	return (flags->length);
}

int	d_yes_width_yes_prec_yesminus(t_list *flags, long long d, \
int i, long long j)
{
	if (d < 0)
	{
		d = d * -1;
		ft_putchar('-');
	}
	while (i < (flags->precision) - (capac(d)))
	{
		i++;
		ft_putchar('0');
	}
	flags->length = flags->length + i;
	i = 0;
	ft_putnbr(d);
	if (j < 0)
		i++;
	if (flags->precision < capac(d))
		flags->precision = capac(d);
	while (i < (flags->width) - flags->precision)
	{
		ft_putchar(' ');
		i++;
	}
	flags->length = flags->length + i + capac(d);
	return (flags->length);
}

int	d_no_width_no_prec(t_list *flags, long long d)
{
	if (flags->width == 0)
	{
		if (d < 0)
			flags->length++;
		ft_putnbr(d);
		flags->length = flags->length + capac(d);
	}
	return (flags->length);
}
