#include "ft_printf.h"

void	num_before_type(char **start_line, t_list *flags, va_list arg)
{
	char	digetwid[20];
	int		i;

	i = 0;
	if (ft_isdigit(*(*start_line)))
	{
		while (ft_isdigit(*(*start_line)))
		{
			digetwid[i] = **start_line;
			(*start_line)++;
			i++;
		}
		flags->width = ft_atoi(digetwid);
	}
	if (((**start_line == '.') && (*(*start_line + 1) == '*')))
	{
		(*start_line)++;
		flags->precision = va_arg(arg, int);
		flags->is_precision = 1;
		(*start_line)++;
	}
}

void	num_before_type_2(char **start_line, t_list *flags)
{
	char	digetpre[20];
	int		i;

	i = 0;
	if ((**start_line == '.') && (!(ft_isdigit(*(*start_line + 1)))))
	{
		flags->zero = 0;
		(*start_line)++;
		flags->for_s = 1;
	}
	if ((**start_line == '.') && (ft_isdigit(*(*start_line + 1))))
	{
		(*start_line)++;
		i = 0;
		while (ft_isdigit(*(*start_line)))
		{
			digetpre[i] = **start_line;
			(*start_line)++;
			i++;
		}
		flags->precision = ft_atoi(digetpre);
		flags->is_precision = 1;
	}
}
