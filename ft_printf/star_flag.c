#include "ft_printf.h"

void	star_flag(char **start_line, t_list *flags, va_list arg)
{
	char	digit[20];
	char	digetwid[20];
	int		i;

	i = 0;
	if (**start_line == '*')
		width_star(start_line, flags, arg);
	if (ft_isdigit(*(*start_line)))
		width_digit(start_line, flags, digetwid, i);
	if (((**start_line == '.') && (*(*start_line + 1) == '*')))
		width_prec_star(start_line, flags, arg);
	if (**start_line == '.' && (*(*start_line + 1) == '-'))
		prec_minus(start_line, flags, digetwid, i);
	if (**start_line == '.')
		point(start_line, flags);
	i = 0;
	if ((ft_isdigit(*(*start_line))))
		width_prec_star_on(digit, start_line, flags, i);
}

void	width_prec_star_on(char digit[20], char **start_line, \
t_list *flags, int i)
{
	i = 0;
	while (digit[i])
	{
		digit[i] = 0;
		i++;
	}
	i = 0;
	while (ft_isdigit(*(*start_line)))
	{
		digit[i] = **start_line;
		(*start_line)++;
		i++;
	}
	flags->precision = ft_atoi(digit);
	flags->is_precision = 1;
}

void	width_star(char **start_line, t_list *flags, va_list arg)
{
	flags->width = va_arg(arg, int);
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	(*start_line)++;
}

void	width_digit(char **start_line, t_list *flags, char digetwid[20], int i)
{
	i = 0;
	while (digetwid[i])
	{
		digetwid[i] = 0;
		i++;
	}
	i = 0;
	while (ft_isdigit(*(*start_line)))
	{
		digetwid[i] = **start_line;
		(*start_line)++;
		i++;
	}
	flags->width = ft_atoi(digetwid);
}

void	width_prec_star(char **start_line, t_list *flags, va_list arg)
{
	(*start_line)++;
	flags->precision = va_arg(arg, int);
	flags->is_precision = 1;
	(*start_line)++;
	if (flags->precision < 0)
	{
		flags->is_precision = -1;
	}
	else if (flags->precision == 0)
	{
		flags->for_s = 1;
		flags->is_precision = -1;
		flags->zero = 0;
	}
}
