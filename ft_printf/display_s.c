#include "ft_printf.h"

void	display_s (va_list arg, t_list *flags)
{
	size_t	i;
	char	*string;

	i = 0;
	if (flags->for_s == 1)
		flags->is_precision = 1;
	string = va_arg(arg, char *);
	if (string == NULL)
		string = "(null)";
	if (flags->is_precision > 0)
	{
		if (flags->width == 0)
			flags->length = s_widthoff_precon(flags, i, string);
		if (flags->width != 0 && flags->minus == 0)
			flags->length = s_precon_widthon_minusoff(string, i, flags);
		if (flags->width != 0 && flags->minus != 0)
			flags->length = s_precon_widthon_minuson(string, i, flags);
	}
	if (flags->is_precision < 0)
	{
		if (flags->minus != 0)
			flags->length = s_precoff_minuson(string, i, flags);
		if (flags->minus == 0)
			flags->length = s_precoff_minusoff(string, i, flags);
	}
}

int	s_widthoff_precon(t_list *flags, size_t i, char *string)
{
	while ((int)i < flags->precision && i < ft_strlen(string))
		ft_putchar(string[i++]);
	flags->length = flags->length + i;
	return (flags->length);
}

int	s_precon_widthon_minusoff(char *string, size_t i, t_list *flags)
{
	if (flags->precision > (int)ft_strlen(string))
		flags->precision = ft_strlen(string);
	while ((int)i++ < flags->width - flags->precision)
		ft_putchar(' ');
	flags->length = flags->length + i;
	i = 0;
	while ((int)i < flags->precision)
		ft_putchar(string[i++]);
	flags->length = flags->length + (i - 1);
	return (flags->length);
}

int	s_precon_widthon_minuson(char *string, size_t i, t_list *flags)
{
	i = 0;
	if (flags->precision > (int)ft_strlen(string))
		flags->precision = (int)ft_strlen(string);
	while ((int)i < flags->precision)
		ft_putchar(string[i++]);
	flags->length = flags->length + i;
	i = 0;
	while ((int)i++ < flags->width - flags->precision)
		ft_putchar(' ');
	flags->length = flags->length + (i - 1);
	return (flags->length);
}

int	s_precoff_minuson(char *string, size_t i, t_list *flags)
{
	if (flags->width <= (int)ft_strlen(string))
		flags->width = ft_strlen(string);
	while (i < ft_strlen(string))
		ft_putchar(string[i++]);
	while ((int)i++ < flags->width)
		ft_putchar(' ');
	flags->length = flags->length + (i - 1);
	return (flags->length);
}
