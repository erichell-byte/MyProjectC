#include "ft_printf.h"

int	s_precoff_minusoff(char *string, size_t i, t_list *flags)
{
	i = 0;
	if (flags->width <= (int)ft_strlen(string))
		flags->width = ft_strlen(string);
	if (flags->zero != 0)
	{
		while ((int)i < (flags->width - (int)ft_strlen(string)))
		{
			ft_putchar('0');
			i++;
		}	
	}
	while (i++ < (flags->width - ft_strlen(string)))
		ft_putchar(' ');
	flags->length = flags->length + i;
	i = 0;
	while (i < ft_strlen(string))
		ft_putchar(string[i++]);
	flags->length = flags->length + (i - 1);
	return (flags->length);
}
