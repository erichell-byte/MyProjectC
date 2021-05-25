#include "ft_printf.h"

void	display_proc(t_list *flags)
{
	size_t	i;

	i = 0;
	if (flags->minus != 0)
	{
		ft_putchar('%');
		i = ft_vakum_put(flags);
		flags->length = flags->length + i;
	}
	else if (flags->minus == 0)
	{
		i = 0;
		if (flags->zero != 0)
			i = ft_zero_put(flags);
		else if (flags->zero == 0)
			i = ft_vakum_put(flags);
		ft_putchar ('%');
		flags->length = flags->length + i;
	}
}

int	ft_zero_put(t_list *flags)
{
	int	i;

	i = 0;
	while ((int)i++ < (flags->width - 1))
		ft_putchar('0');
	return (i);
}

int	ft_vakum_put(t_list *flags)
{
	int	i;

	i = 0;
	while ((int)i++ < (flags->width - 1))
		ft_putchar(' ');
	return (i);
}
