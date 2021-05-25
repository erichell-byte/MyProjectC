#include "ft_printf.h"

void	prec_minus(char **start_line, t_list *flags, char digetwid[20], int i)
{
	i = 0;
	while (digetwid[i])
	{
		digetwid[i] = 0;
		i++;
	}
	i = 0;
	(*start_line)++;
	while (**start_line == '-')
		(*start_line)++;
	while (ft_isdigit(*(*start_line)))
	{
		digetwid[i] = **start_line;
		(*start_line)++;
		i++;
	}
	flags->width = ft_atoi(digetwid);
	flags->is_precision = -1;
	flags->precision = 0;
	flags->for_s = 1;
	flags->minus = 1;
}

void	point(char **start_line, t_list *flags)
{
	(*start_line)++;
	while (**start_line == '0')
		(*start_line)++;
	if (((**start_line < '1' || **start_line > '9') && **start_line != '*'))
	{
		flags->is_precision = -1;
		flags->zero = 0;
		flags->for_s = 1;
	}
}
