#include "ft_printf.h"

void	zero_minus_flag(char **start_line, t_list *flags)
{
	if (**start_line == '0')
		flags->zero = 1;
	while (**start_line == '0')
		(*start_line)++;
	if (**start_line == '-')
	{
		flags->zero = 0;
		flags->minus = 1;
	}
	while (**start_line == '-' || **start_line == '0')
		(*start_line)++;
}

void	check_type(char **start_line, t_list *flags, va_list arg)
{
	if (**start_line == 'd')
		display_d(arg, flags, start_line);
	else if (**start_line == 'i')
		display_d(arg, flags, start_line);
	else if (**start_line == 'u')
		display_d(arg, flags, start_line);
	else if (**start_line == 's')
		display_s(arg, flags);
	else if (**start_line == 'c')
		display_c(arg, flags);
	else if (**start_line == 'p')
		display_p(arg, flags);
	else if (**start_line == 'X')
		display_XX(arg, flags);
	else if (**start_line == 'x')
		display_x(arg, flags);
	else if (**start_line == '%')
		display_proc(flags);
}

int	check_flags(char **start_line, t_list *flags, va_list arg)
{
	(*start_line)++;
	zero_minus_flag(start_line, flags);
	star_flag(start_line, flags, arg);
	num_before_type(start_line, flags, arg);
	num_before_type_2(start_line, flags);
	check_type(start_line, flags, arg);
	return (flags->length);
}

void	zero_flags(t_list *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->is_precision = -1;
	flags->star = 0;
	flags->for_s = 0;
}

int	ft_printf(const char *line, ...)
{
	va_list	arg;
	t_list	flags;
	char	*start_line;

	start_line = (char *)line;
	va_start(arg, line);
	flags.length = 0;
	while (*start_line != '\0')
	{
		if (*start_line == '%')
		{
			zero_flags(&flags);
			check_flags(&start_line, &flags, arg);
			if (*start_line == '\0')
				break ;
		}
		else
		{
			ft_putchar(*start_line);
			flags.length++;
		}
		start_line++;
	}
	va_end(arg);
	return (flags.length);
}
