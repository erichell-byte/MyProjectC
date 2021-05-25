#include "ft_printf.h"

int	d_yes_width_no_prec_minus(t_list *flags, long long d)
{
	int	i;

	i = 0;
	if (flags->for_s == 1 && d == 0)
		i--;
	else
		ft_putnbr(d);
	if (d < 0)
		i++;
	while (i++ < (flags->width - capac(d)))
		ft_putchar(' ');
	flags->length = flags->length + (i - 1) + capac(d);
	return (flags->length);
}

int	d_yes_width_no_prec_nominus(t_list *flags, long long d, int i)
{
	if (d < 0)
	{
		i++;
		d = d * -1;
		ft_putchar('-');
	}
	while (i++ < (flags->width - capac(d)))
		ft_putchar('0');
	if (flags->for_s == 1 && d == 0)
		i--;
	else
		ft_putnbr(d);
	flags->length = flags->length + (i - 1) + capac(d);
	return (flags->length);
}

int	d_yes_width_no_prec_nozero(t_list *flags, long long d, int i)
{
	if (d < 0)
		i++;
	while (i++ < (flags->width - capac(d)))
		ft_putchar(' ');
	if (flags->for_s == 1 && d == 0)
		i--;
	else
		ft_putnbr(d);
	flags->length = flags->length + (i - 1) + capac(d);
	return (flags->length);
}

int	d_null(t_list *flags)
{
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		flags->length++;
	}
	return (flags->length);
}

int	d_precision_no(t_list *flags, long long d, int i)
{	
	if (flags->width == 0)
		flags->length = d_no_width_no_prec(flags, d);
	else if (flags->minus != 0)
		flags->length = d_yes_width_no_prec_minus(flags, d);
	else if (flags->minus == 0)
	{
		if (flags->zero != 0)
			flags->length = d_yes_width_no_prec_nominus(flags, d, i);
		if (flags->zero == 0)
			flags->length = d_yes_width_no_prec_nozero(flags, d, i);
	}
	return (flags->length);
}
