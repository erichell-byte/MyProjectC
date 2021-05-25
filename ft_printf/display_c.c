#include "ft_printf.h"

void	display_c (va_list arg, t_list *flags)
{
	size_t	i;
	char	c;

	c = va_arg(arg, int);
	if (flags->is_precision < 0)
	{
		i = 0;
		if (flags->minus != 0)
		{
			ft_putchar(c);
			while ((int)i++ < (flags->width - 1))
				ft_putchar(' ');
			flags->length = flags->length + i;
		}
		if (flags->minus == 0)
		{
			i = 0;
			while ((int)i++ < (flags->width - 1))
				ft_putchar(' ');
			ft_putchar(c);
			flags->length = flags->length + i;
		}
	}
}
// если минуса нет (flags->minus == 0)
// Если нету точности (flags->is_precision < 0)
// если есть минус (flags->minus != 0)
